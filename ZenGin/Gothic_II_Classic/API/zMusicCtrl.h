// Supported with union (c) 2018 Union team

#ifndef __ZMUSIC_CTRL_H__VER2__
#define __ZMUSIC_CTRL_H__VER2__

namespace Gothic_II_Classic {

  class zCEventMusicControler : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCEventMusicControler )

    enum zTEventMusicControlerSubType {
      zEVENT_START_SPECIAL_SGT,
      zEVENT_STOP_SPECIAL_SGT,
      zEVENT_MUSICCONTROLER_COUNT
    };

    zSTRING sgt;

    zCEventMusicControler() {}
    static zCObject* _CreateNewInstance()                       zCall( 0x007573C0 );
    static void operator delete( void* )                        zCall( 0x00757560 );
    virtual zCClassDef* _GetClassDef() const                    zCall( 0x00757580 );
    virtual void Archive( zCArchiver& )                         zCall( 0x00757740 );
    virtual void Unarchive( zCArchiver& )                       zCall( 0x00757770 );
    virtual ~zCEventMusicControler()                            zCall( 0x007575D0 );
    virtual int MD_GetNumOfSubTypes()                           zCall( 0x00757590 );
    virtual zSTRING MD_GetSubTypeString( int )                  zCall( 0x00757620 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior() zCall( 0x00757720 );
    virtual float MD_GetMinTime()                               zCall( 0x00757730 );
  };

  class zCMusicControler : public zCEffect {
  public:
    zCLASS_DECLARATION( zCMusicControler )

    void zCMusicControler_OnInit()                    zCall( 0x007577A0 );
    zCMusicControler()                                zInit( zCMusicControler_OnInit() );
    static zCObject* _CreateNewInstance()             zCall( 0x00757150 );
    static void operator delete( void* )              zCall( 0x007571B0 );
    virtual zCClassDef* _GetClassDef() const          zCall( 0x007571D0 );
    virtual ~zCMusicControler()                       zCall( 0x007577F0 );
    virtual void OnMessage( zCEventMessage*, zCVob* ) zCall( 0x00757800 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )  zCall( 0x00757860 );
  };

} // namespace Gothic_II_Classic

#endif // __ZMUSIC_CTRL_H__VER2__