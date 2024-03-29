// Supported with union (c) 2018 Union team

#ifndef __ZSOUND_H__VER3__
#define __ZSOUND_H__VER3__

#include "zResource.h"

namespace Gothic_II_Addon {
  const int zSND_FREQ_DEFAULT         = -1;
  const float zSND_PAN_DEFAULT        = -2;
  const float zSND_PAN_LEFT           =-1.0F;
  const float zSND_PAN_CENTER         = 0.0F;
  const float zSND_PAN_RIGHT          = 1.0F;
  const float zSND_PAN_SURROUND       = 100.0F;
  const int zSND_SLOT_NONE            = 0;
  const int zSND_SLOT_MAX             = 8;
  const int zSND_CHANNEL_FRAME_RANDOM =-1;

  class zCSoundSystem {
  public:
    enum zTLoopType {
      zSND_LOOPING_DEFAULT,
      zSND_LOOPING_ENABLED,
      zSND_LOOPING_DISABLED
    };

    enum zTSpeakerType {
      zSPEAKER_TYPE_2_SPEAKER,
      zSPEAKER_TYPE_HEADPHONE,
      zSPEAKER_TYPE_SURROUND,
      zSPEAKER_TYPE_4_SPEAKER,
      zSPEAKER_TYPE_51_SPEAKER,
      zSPEAKER_TYPE_71_SPEAKER,
      zMaxSpeakerType
    };

    struct zTSound3DParams {
      float obstruction;
      float volume;
      float radius;
      zTLoopType loopType;
      float coneAngleDeg;
      float reverbLevel;
      int isAmbient3D;
      float pitchOffset;

      zTSound3DParams() {}
      void SetDefaults() zCall( 0x00612F50 );
    };

    float defaultRadius;

    zCSoundSystem() {}
    int GetNumReverbPresets()                                                zCall( 0x005EC060 );
    zSTRING const* GetReverbPresetName( int )                                zCall( 0x005EC070 );
    virtual ~zCSoundSystem()                                                 zCall( 0x004EB350 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                         zCall( 0x004EB360 );
    virtual zCSoundFX* LoadSoundFXScript( zSTRING const& )                   zCall( 0x004EB370 );
    virtual zCParser* GetSFXParser()                                         zCall( 0x004EB380 );
    virtual float GetPlayingTimeMSEC( zSTRING const& )                       zCall( 0x004EB390 );
    virtual void SetSound3DDefaultRadius( float )                            zCall( 0x004EB3A0 );
    virtual float GetSound3DDefaultRadius() const                            zCall( 0x004EB3B0 );
    virtual void SetMasterVolume( float )                                    zCall( 0x004EB3C0 );
    virtual float GetMasterVolume()                                          zCall( 0x004EB3D0 );
    virtual int PlaySound( zCSoundFX*, int )                                 zPureCall;
    virtual int PlaySound( zCSoundFX*, int, int, float, float )              zPureCall;
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zTSound3DParams* )     zPureCall;
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zTSound3DParams* ) zPureCall;
    virtual void StopSound( int const& )                                     zCall( 0x004EB3E0 );
    virtual void StopAllSounds()                                             zCall( 0x004EB3F0 );
    virtual int GetSound3DProps( int const&, zTSound3DParams& )              zPureCall;
    virtual int UpdateSound3D( int const&, zTSound3DParams* )                zPureCall;
    virtual void GetSoundProps( int const&, int&, float&, float& )           zCall( 0x004EB400 );
    virtual void UpdateSoundProps( int const&, int, float, float )           zCall( 0x004EB410 );
    virtual int IsSoundActive( int const& )                                  zCall( 0x004EB420 );
    virtual void DoSoundUpdate()                                             zPureCall;
    virtual void SetListener( zCVob* )                                       zCall( 0x004EB430 );
    virtual void SetGlobalReverbPreset( int, float )                         zCall( 0x004EB440 );
    virtual void SetReverbEnabled( int )                                     zCall( 0x004EB450 );
    virtual int GetReverbEnabled()                                           zCall( 0x004EB460 );
    virtual int GetNumProvider()                                             zCall( 0x004EB470 );
    virtual zSTRING const* GetProviderName( int )                            zCall( 0x004EB480 );
    virtual int SetProvider( int )                                           zCall( 0x004EB490 );
    virtual void SetSpeakerType( zTSpeakerType )                             zCall( 0x004EB4A0 );
    virtual zTSpeakerType GetSpeakerType()                                   zCall( 0x004EB4B0 );
    virtual void SetGlobalOcclusion( float )                                 zPureCall;
    virtual float GetCPULoad()                                               zCall( 0x004EB4C0 );
  };

  class zCSoundFX : public zCResource {
  public:
    zCLASS_DECLARATION( zCSoundFX )

    void zCSoundFX_OnInit()                                       zCall( 0x004EDF50 );
    zCSoundFX()                                                   zInit( zCSoundFX_OnInit() );
    static void operator delete( void* )                          zCall( 0x004EDF20 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x004EDF40 );
    virtual ~zCSoundFX()                                          zCall( 0x004EDF70 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& ) zCall( 0x005EC090 );
    virtual int GetNumChannels() const                            zCall( 0x004EDF80 );
    virtual int GetNumChannelFrames( int ) const                  zCall( 0x004EDF90 );
    virtual void GetChannelFrame( int, int ) const                zCall( 0x004EDFA0 );
    virtual void SetChannelFrame( int, int )                      zCall( 0x004EDFB0 );
    virtual float GetPlayingTimeMSEC() const                      zCall( 0x004EDFC0 );
    virtual float GetPan() const                                  zCall( 0x004EDFD0 );
    virtual void SetPan( float )                                  zCall( 0x004EDFE0 );
    virtual float GetVolume() const                               zCall( 0x004EDFF0 );
    virtual void SetVolume( float )                               zCall( 0x004EE000 );
    virtual int GetFrequency() const                              zCall( 0x004EE010 );
    virtual void SetFrequency( int )                              zCall( 0x004EE020 );
    virtual void SetLooping( int )                                zCall( 0x004EE030 );
    virtual int IsLooping() const                                 zCall( 0x004EE040 );
    virtual void SetIsFixed( int )                                zCall( 0x004EE050 );
    virtual int GetIsFixed() const                                zCall( 0x004EE060 );
  };

  class zCSoundFXDummy : public zCSoundFX {
  public:

    zCSoundFXDummy() {}
    virtual ~zCSoundFXDummy() zCall( 0x00632B50 );
  };

  class zCSoundSystemDummy : public zCSoundSystem {
  public:

    zCSoundSystemDummy() {}
    virtual ~zCSoundSystemDummy()                                                           zCall( 0x00639030 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                                        zCall( 0x00632AC0 );
    virtual int PlaySound( zCSoundFX*, int )                                                zCall( 0x00632B60 );
    virtual int PlaySound( zCSoundFX*, int, int, float, float )                             zCall( 0x00632B70 );
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )     zCall( 0x00632B90 );
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zCSoundSystem::zTSound3DParams* ) zCall( 0x00632BA0 );
    virtual int GetSound3DProps( int const&, zCSoundSystem::zTSound3DParams& )              zCall( 0x00632BB0 );
    virtual int UpdateSound3D( int const&, zCSoundSystem::zTSound3DParams* )                zCall( 0x00632BC0 );
    virtual void DoSoundUpdate()                                                            zCall( 0x00632AB0 );
    virtual void SetGlobalOcclusion( float )                                                zCall( 0x00632B80 );
  };

} // namespace Gothic_II_Addon

#endif // __ZSOUND_H__VER3__