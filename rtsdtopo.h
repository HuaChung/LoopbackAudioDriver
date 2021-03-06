/*
Module Name:
  rtsdtopo.h

Abstract:
  Declaration of topology miniport.
*/

#ifndef __RTSDTOPO_H_
#define __RTSDTOPO_H_

//=============================================================================
// Classes
//=============================================================================

///////////////////////////////////////////////////////////////////////////////
// CMiniportTopology 
//   

class CMiniportTopology : public IMiniportTopology, public CUnknown {
  protected:
    PADAPTERCOMMON              m_AdapterCommon;    // Adapter common object.
    PPCFILTER_DESCRIPTOR        m_FilterDescriptor; // Filter descriptor.
  public:
    DECLARE_STD_UNKNOWN();
    DEFINE_STD_CONSTRUCTOR(CMiniportTopology);
    ~CMiniportTopology();

    IMP_IMiniportTopology;

    NTSTATUS Init( 
        IN  PUNKNOWN       UnknownAdapter,
        IN  PPORTTOPOLOGY  Port_ 
    );

    // PropertyHandlers
    NTSTATUS PropertyHandlerBasicSupportVolume(
        IN  PPCPROPERTY_REQUEST PropertyRequest
    );
    
    NTSTATUS PropertyHandlerCpuResources( 
        IN  PPCPROPERTY_REQUEST PropertyRequest 
    );

    NTSTATUS PropertyHandlerGeneric(
        IN  PPCPROPERTY_REQUEST PropertyRequest
    );

    NTSTATUS PropertyHandlerMute(
        IN  PPCPROPERTY_REQUEST PropertyRequest
    );

    NTSTATUS PropertyHandlerMuxSource(
        IN  PPCPROPERTY_REQUEST PropertyRequest
    );

    NTSTATUS PropertyHandlerVolume(
        IN  PPCPROPERTY_REQUEST PropertyRequest
    );
};
typedef CMiniportTopology *PCMiniportTopology;

#endif
