// Supported with union (c) 2018 Union team

#ifndef __ZEVENT_MAN_H__VER2__
#define __ZEVENT_MAN_H__VER2__

#include "zVob.h"
#include "zArchiver.h"

namespace Gothic_II_Classic {

  class zCEventManager : public zCObject {
  public:
    zCLASS_DECLARATION( zCEventManager )

    zEVENT_INTERFACE

    int cleared;
    int active;
    zCCutscene* cutscene;
    zCArray<zCEventMessage*>messageList;
    zCVob* hostVob;

    void zCEventManager_OnInit()                                      zCall( 0x00726570 );
    void zCEventManager_OnInit( zCVob* )                              zCall( 0x007266C0 );
    zCEventManager()                                                  zInit( zCEventManager_OnInit() );
    zCEventManager( zCVob* a0 )                                       zInit( zCEventManager_OnInit( a0 ));
    void KillMessages()                                               zCall( 0x007268E0 );
    void ShowMessageCommunication( zCVob*, zCVob* )                   zCall( 0x007273E0 );
    void Print_db( zSTRING const&, zCVob* )                           zCall( 0x00727E10 );
    static void operator delete( void* )                              zCall( 0x005A6520 );
    static zCObject* _CreateNewInstance()                             zCall( 0x00726370 );
    static void DoFrameActivity()                                     zCall( 0x00726530 );
    static void SetShowMessageCommunication( int )                    zCall( 0x007273C0 );
    static int GetShowMessageCommunication()                          zCall( 0x007273D0 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x007264C0 );
    virtual void Archive( zCArchiver& )                               zCall( 0x007284C0 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x00728500 );
    virtual ~zCEventManager()                                         zCall( 0x007267F0 );
    virtual void OnTrigger( zCVob*, zCVob* )                          zCall( 0x00727FB0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                        zCall( 0x00728070 );
    virtual void OnTouch( zCVob* )                                    zCall( 0x00727E20 );
    virtual void OnUntouch( zCVob* )                                  zCall( 0x00727EE0 );
    virtual void OnTouchLevel()                                       zCall( 0x00727FA0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& ) zCall( 0x00728130 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                 zCall( 0x00726940 );
    virtual void Clear()                                              zCall( 0x00727B40 );
    virtual int IsEmpty( int )                                        zCall( 0x00727D40 );
    virtual int GetCutsceneMode()                                     zCall( 0x00727B30 );
    virtual void SetCutscene( zCCutscene* )                           zCall( 0x00727AB0 );
    virtual zCCutscene* GetCutscene()                                 zCall( 0x00727B20 );
    virtual int IsRunning( zCEventMessage* )                          zCall( 0x00727DA0 );
    virtual void SetActive( int )                                     zCall( 0x007276D0 );
    virtual int GetNumMessages()                                      zCall( 0x00456CE0 );
    virtual zCEventMessage* GetEventMessage( int )                    zCall( 0x00728200 );
    virtual zCEventMessage* GetActiveMessage()                        zCall( 0x00727DD0 );
    virtual void ShowList( int, int )                                 zCall( 0x00728210 );
    virtual zCNetVobControl* GetNetVobControl( int )                  zCall( 0x007264D0 );
    virtual void RemoveFromList( zCEventMessage* )                    zCall( 0x00727870 );
    virtual void InsertInList( zCEventMessage* )                      zCall( 0x007278C0 );
    virtual void ProcessMessageList()                                 zCall( 0x007275C0 );
    virtual void SendMessageToHost( zCEventMessage*, zCVob*, zCVob* ) zCall( 0x00727220 );
    virtual void Delete( zCEventMessage* )                            zCall( 0x00727830 );

    // static properties
    static int& disableEventManagers;
    static zCArray<zCEventManager*>& activeEM;
    static int& showMsgCommunication;
  };

} // namespace Gothic_II_Classic

#endif // __ZEVENT_MAN_H__VER2__