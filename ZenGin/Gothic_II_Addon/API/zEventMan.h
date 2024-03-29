// Supported with union (c) 2018 Union team

#ifndef __ZEVENT_MAN_H__VER3__
#define __ZEVENT_MAN_H__VER3__

#include "zVob.h"
#include "zArchiver.h"

namespace Gothic_II_Addon {

  class zCEventManager : public zCObject {
  public:
    zCLASS_DECLARATION( zCEventManager )

    zEVENT_INTERFACE

    int cleared;
    int active;
    zCCutscene* cutscene;
    zCArray<zCEventMessage*>messageList;
    zCVob* hostVob;

    void zCEventManager_OnInit()                                      zCall( 0x00785FB0 );
    void zCEventManager_OnInit( zCVob* )                              zCall( 0x00786100 );
    zCEventManager()                                                  zInit( zCEventManager_OnInit() );
    zCEventManager( zCVob* a0 )                                       zInit( zCEventManager_OnInit( a0 ));
    void KillMessages()                                               zCall( 0x00786320 );
    void ShowMessageCommunication( zCVob*, zCVob* )                   zCall( 0x00786E20 );
    void Print_db( zSTRING const&, zCVob* )                           zCall( 0x00787850 );
    static void operator delete( void* )                              zCall( 0x005ABA80 );
    static zCObject* _CreateNewInstance()                             zCall( 0x00785DB0 );
    static void DoFrameActivity()                                     zCall( 0x00785F70 );
    static void SetShowMessageCommunication( int )                    zCall( 0x00786E00 );
    static int GetShowMessageCommunication()                          zCall( 0x00786E10 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x00785F00 );
    virtual void Archive( zCArchiver& )                               zCall( 0x00787F00 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x00787F40 );
    virtual ~zCEventManager()                                         zCall( 0x00786230 );
    virtual void OnTrigger( zCVob*, zCVob* )                          zCall( 0x007879F0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                        zCall( 0x00787AB0 );
    virtual void OnTouch( zCVob* )                                    zCall( 0x00787860 );
    virtual void OnUntouch( zCVob* )                                  zCall( 0x00787920 );
    virtual void OnTouchLevel()                                       zCall( 0x007879E0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& ) zCall( 0x00787B70 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                 zCall( 0x00786380 );
    virtual void Clear()                                              zCall( 0x00787580 );
    virtual int IsEmpty( int )                                        zCall( 0x00787780 );
    virtual int GetCutsceneMode()                                     zCall( 0x00787570 );
    virtual void SetCutscene( zCCutscene* )                           zCall( 0x007874F0 );
    virtual zCCutscene* GetCutscene()                                 zCall( 0x00787560 );
    virtual int IsRunning( zCEventMessage* )                          zCall( 0x007877E0 );
    virtual void SetActive( int )                                     zCall( 0x00787110 );
    virtual int GetNumMessages()                                      zCall( 0x00457430 );
    virtual zCEventMessage* GetEventMessage( int )                    zCall( 0x00787C40 );
    virtual zCEventMessage* GetActiveMessage()                        zCall( 0x00787810 );
    virtual void ShowList( int, int )                                 zCall( 0x00787C50 );
    virtual zCNetVobControl* GetNetVobControl( int )                  zCall( 0x00785F10 );
    virtual void RemoveFromList( zCEventMessage* )                    zCall( 0x007872B0 );
    virtual void InsertInList( zCEventMessage* )                      zCall( 0x00787300 );
    virtual void ProcessMessageList()                                 zCall( 0x00787000 );
    virtual void SendMessageToHost( zCEventMessage*, zCVob*, zCVob* ) zCall( 0x00786C60 );
    virtual void Delete( zCEventMessage* )                            zCall( 0x00787270 );

    // static properties
    static int& disableEventManagers;
    static zCArray<zCEventManager*>& activeEM;
    static int& showMsgCommunication;
  };

} // namespace Gothic_II_Addon

#endif // __ZEVENT_MAN_H__VER3__