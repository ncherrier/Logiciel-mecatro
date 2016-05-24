/*=============================================================================
  Copyright (C) 2012 Allied Vision Technologies.  All Rights Reserved.

  Redistribution of this file, in original or modified form, without
  prior written consent of Allied Vision Technologies is prohibited.

-------------------------------------------------------------------------------

  File:        IInterfaceListObserver.h

  Description: Definition of interface AVT::VmbAPI::IInterfaceListObserver.

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

#ifndef AVT_VMBAPI_IINTERFACELISTOBSERVER_H
#define AVT_VMBAPI_IINTERFACELISTOBSERVER_H

#include <Vimba_2.0/VimbaCPP/Include/VimbaCPPCommon.h>
#include <Vimba_2.0/VimbaCPP/Include/SharedPointerDefines.h>
#include <Vimba_2.0/VimbaCPP/Include/Interface.h>
#include <vector>

namespace AVT {
namespace VmbAPI {

class IMEXPORT IInterfaceListObserver
{
  public:
    //
    // Method:      InterfaceListChanged()
    //
    // Purpose:     The event handler function that gets called whenever
    //              an IInterfaceListObserver is triggered.
    //
    // Parameters:
    //
    // [out]    InterfacePtr        pInterface              The interface that triggered the event
    // [out]    UpdateTriggerType   reason                  The reason why the callback routine was triggered
    //
    virtual void InterfaceListChanged( InterfacePtr pInterface, UpdateTriggerType reason ) = 0;

    //
    // Method:      IInterfaceListObserver destructor
    //
    // Purpose:     Destroys an instance of class IInterfaceListObserver
    //
    virtual ~IInterfaceListObserver() {}

  protected:
    IInterfaceListObserver() {};
    IInterfaceListObserver( const IInterfaceListObserver& ) { /* No copy ctor */ }
    IInterfaceListObserver& operator=( const IInterfaceListObserver& ) { /* No assignment operator */ return *this; }
    
};
typedef std::vector<IInterfaceListObserverPtr> IInterfaceListObserverPtrVector;

}} // namespace AVT::VmbAPI

#endif
