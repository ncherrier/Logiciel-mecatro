/*=============================================================================
  Copyright (C) 2012 - 2016 Allied Vision Technologies.  All Rights Reserved.

  Redistribution of this file, in original or modified form, without
  prior written consent of Allied Vision Technologies is prohibited.

-------------------------------------------------------------------------------

  File:        ApiController.cpp

  Description: Implementation file for the ApiController helper class that
               demonstrates how to implement a synchronous single image
               acquisition with VimbaCPP.

-------------------------------------------------------------------------------

  THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF TITLE,
  NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE ARE
  DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/
#include "stdafx.h"

#include <iostream>
#include <sstream>

#include "ApiController.h"


#ifndef UNICODE
    typedef std::ostringstream      string_stream_type;
#else
    typedef std::wostringstream     string_stream_type;
#endif

namespace AVT {
namespace VmbAPI {
namespace Examples {

#define NUM_FRAMES 3

ApiController::ApiController()
    // Get a reference to the Vimba singleton
    : m_system ( VimbaSystem::GetInstance() )
{}

ApiController::~ApiController()
{
}

//
// Starts the Vimba API and loads all transport layers
//
// Returns:
//  An API status code
//
VmbErrorType ApiController::StartUp()
{
    VmbErrorType res;

    // Start Vimba
    res = m_system.Startup();
    if ( VmbErrorSuccess == res )
    {
        // Register an observer whose callback routine gets triggered whenever a camera is plugged in or out
        res = m_system.RegisterCameraListObserver( ICameraListObserverPtr( new CameraObserver() ));
    }
    
    return res;
}

//
// Shuts down the API
//
void ApiController::ShutDown()
{
    // Release Vimba
    m_system.Shutdown();
}

//
// Opens the given camera
// Sets the maximum possible Ethernet packet size
// Adjusts the image format
// Calls the API convenience function to start single image acquisition
// Closes the camera in case of failure
//
// Parameters:
//  [in]    rStrCameraID        The ID of the camera to work on
//  [out]   rpFrame             The frame that will be filled. Does not need to be initialized.
//
// Returns:
//  An API status code
//
VmbErrorType ApiController::AcquireSingleImage( const std::string &rStrCameraID, FramePtr &rpFrame )
{
    // Open the desired camera by its ID
    VmbErrorType res = m_system.OpenCameraByID( rStrCameraID.c_str(), VmbAccessModeFull, m_pCamera );
    if ( VmbErrorSuccess == res )
    {
        // Set the GeV packet size to the highest possible value
        // (In this example we do not test whether this cam actually is a GigE cam)
        FeaturePtr pCommandFeature;
        if ( VmbErrorSuccess == m_pCamera->GetFeatureByName( "GVSPAdjustPacketSize", pCommandFeature ))
        {
            if ( VmbErrorSuccess == pCommandFeature->RunCommand() )
            {
                bool bIsCommandDone = false;
                do
                {
                    if ( VmbErrorSuccess != pCommandFeature->IsCommandDone( bIsCommandDone ))
                    {
                        break;
                    }
                } while ( false == bIsCommandDone );
            }
        }
        FeaturePtr pFormatFeature;
        // Save the current width
        res = m_pCamera->GetFeatureByName( "Width", pFormatFeature );
        if ( VmbErrorSuccess == res )
        {
            res = pFormatFeature->GetValue( m_nWidth );
            if ( VmbErrorSuccess == res )
            {
                // Save the current height
                res = m_pCamera->GetFeatureByName( "Height", pFormatFeature );
                if ( VmbErrorSuccess == res )
                {
                    pFormatFeature->GetValue( this->m_nHeight );
                    if ( VmbErrorSuccess == res )
                    {
                        // Set pixel format. For the sake of simplicity we only support Mono and BGR in this example.
                        res = m_pCamera->GetFeatureByName( "PixelFormat", pFormatFeature );
                        if ( VmbErrorSuccess == res )
                        {
                            // Try to set BGR
                            res = pFormatFeature->SetValue( VmbPixelFormatBgr8 );
                            if ( VmbErrorSuccess != res )
                            {
                                // Fall back to Mono
                                res = pFormatFeature->SetValue( VmbPixelFormatMono8 );
                            }

                            // Read back the currently selected pixel format
                            pFormatFeature->GetValue( m_nPixelFormat );

                            if ( VmbErrorSuccess == res )
                            {
                                // Acquire
                                res = m_pCamera->AcquireSingleImage( rpFrame, 2000 );
                            }
                        }
                    }
                }
            }
        }
        m_pCamera->Close();
    }

    return res;
}

//
// Gets all cameras known to Vimba
//
// Returns:
//  A vector of camera shared pointers
//
CameraPtrVector ApiController::GetCameraList() const
{
    CameraPtrVector cameras;
    // Get all known cameras
    if ( VmbErrorSuccess == m_system.GetCameras( cameras ))
    {
        // And return them
        return cameras;
    }
    return CameraPtrVector();
}

//
// Gets the width of a frame
//
// Returns:
//  The width as integer
//
int ApiController::GetWidth() const
{
    return static_cast<int>( m_nWidth );
}

//
// Gets the height of a frame
//
// Returns:
//  The height as integer
//
int ApiController::GetHeight() const
{
    return static_cast<int>( m_nHeight );
}

//
// Gets the pixel format of a frame
//
// Returns:
//  The pixel format as enum
//
VmbPixelFormatType ApiController::GetPixelFormat() const
{
    return static_cast<VmbPixelFormatType>( m_nPixelFormat );
}

//
// Translates Vimba error codes to readable error messages
//
// Parameters:
//  [in]    eErr        The error code to be converted to string
//
// Returns:
//  A descriptive string representation of the error code
//
string_type ApiController::ErrorCodeToMessage( VmbErrorType eErr ) const
{
    return AVT::VmbAPI::Examples::ErrorCodeToMessage( eErr );
}

//
// Gets the version of the Vimba API
//
// Returns:
//  The version as string
//
string_type ApiController::GetVersion() const
{
    string_stream_type os;
    os<<m_system;
    return os.str() ;
}

}}} // namespace AVT::VmbAPI::Examples
