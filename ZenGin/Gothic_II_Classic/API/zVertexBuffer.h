// Supported with union (c) 2018 Union team

#ifndef __ZVERTEX_BUFFER_H__VER2__
#define __ZVERTEX_BUFFER_H__VER2__

namespace Gothic_II_Classic {

  enum zTVBufferPrimitiveType {
    zVBUFFER_PT_TRIANGLELIST,
    zVBUFFER_PT_TRIANGLESTRIP,
    zVBUFFER_PT_TRIANGLEFAN,
    zVBUFFER_PT_POINTLIST,
    zVBUFFER_PT_LINELIST,
    zVBUFFER_PT_LINESTRIP
  };

  enum zTVBufferCreateFlags {
    zVBUFFER_CREATE_FLAG_DONOTCLIP    = 1,
    zVBUFFER_CREATE_FLAG_OPTIMIZED    = 2,
    zVBUFFER_CREATE_FLAG_SYSTEMMEMORY = 4,
    zVBUFFER_CREATE_FLAG_WRITEONLY    = 8
  };

  enum zTVBufferLockFlags {
    zVBUFFER_LOCK_FLAG_READONLY         = 1,
    zVBUFFER_LOCK_FLAG_SURFACEMEMORYPTR = 2,
    zVBUFFER_LOCK_FLAG_WAIT             = 4,
    zVBUFFER_LOCK_FLAG_WRITEONLY        = 8,
    zVBUFFER_LOCK_FLAG_DISCARDCONTENTS  = 16,
    zVBUFFER_LOCK_FLAG_NOOVERWRITE      = 32,
    zVBUFFER_LOCK_FLAG_NOSYSLOCK        = 64
  };

  enum zTVBufferVertexFormat {
    zVBUFFER_VERTFORMAT_XYZ    = 1,
    zVBUFFER_VERTFORMAT_XYZRHW = 2,
    zVBUFFER_VERTFORMAT_NORMAL = 4,
    zVBUFFER_VERTFORMAT_COLOR  = 8,
    zVBUFFER_VERTFORMAT_TEXUV1 = 16,
    zVBUFFER_VERTFORMAT_TEXUV2 = 32,
    zVBUFFER_VERTFORMAT_TEXUV3 = 64,
    zVBUFFER_VERTFORMAT_TEXUV4 = 128
  };

  enum zTVBufferVertexType {
    zVBUFFER_VERTTYPE_UT_UL,
    zVBUFFER_VERTTYPE_UT_L,
    zVBUFFER_VERTTYPE_T_L
  };

  class zCVertexBuffer : public zCObject {
  public:
    zCLASS_DECLARATION( zCVertexBuffer )

    struct zCVertexBufferDummy0 {
      unsigned char* basePtr;
      zVEC3* XYZPtr;
      zVEC4* XYZRHWPtr;
      zVEC3* normalPtr;
      zCOLOR* colorPtr;
      union {
        group {
          zVEC2* texUV0Ptr;
          zVEC2* texUV1Ptr;
          zVEC2* texUV2Ptr;
          zVEC2* texUV3Ptr;
        };
      };

    };

    struct zTCallbackData {
      void* recreateLostVBCallback;
      void* recreateLostVBCallbackData;

      zTCallbackData() {}
    };

    unsigned long numVertex;
    unsigned long arrayStride;
    zCVertexBufferDummy0 array;
    int numVertsFilled;
    unsigned long createFlags;
    zCArray<zTCallbackData> callbackList;
    unsigned long vertexBufferID;

    void zCVertexBuffer_OnInit()                                                          zCall( 0x005F4F50 );
    void SetXYZ( unsigned long, zVEC3 const& )                                            zCall( 0x005C6DF0 );
    zCVertexBuffer()                                                                      zInit( zCVertexBuffer_OnInit() );
    void AddRecreateLostVBCallback( int( __cdecl* )( zCVertexBuffer*, void* ), void* )    zCall( 0x005F5200 );
    void RemoveRecreateLostVBCallback( int( __cdecl* )( zCVertexBuffer*, void* ), void* ) zCall( 0x005F5310 );
    int CallRecreateLostVBCallbacks()                                                     zCall( 0x005F5370 );
    static void operator delete( void* )                                                  zCall( 0x007654D0 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x005F5070 );
    virtual ~zCVertexBuffer()                                                             zCall( 0x005F5190 );
    virtual int Create( unsigned long, unsigned long, unsigned long )                     zCall( 0x005F5080 );
    virtual int Destroy()                                                                 zCall( 0x005F5090 );
    virtual int Lock( unsigned long )                                                     zCall( 0x005F50A0 );
    virtual int Unlock()                                                                  zCall( 0x005F50B0 );
    virtual int IsLocked()                                                                zCall( 0x005F50C0 );
    virtual int Optimize()                                                                zCall( 0x005F50D0 );
    virtual int SetPrimitiveType( zTVBufferPrimitiveType )                                zCall( 0x005F50E0 );
    virtual zTVBufferPrimitiveType GetPrimitiveType()                                     zCall( 0x005F50F0 );
    virtual unsigned long GetVertexFormat()                                               zCall( 0x005F5100 );
    virtual zTVBufferVertexType GetVertexType()                                           zCall( 0x005F5110 );
    virtual int SetIndexList( zCArray<unsigned short> const& )                            zCall( 0x005F5120 );
    virtual int SetIndexListSize( unsigned long )                                         zCall( 0x005F5130 );
    virtual unsigned long GetIndexListSize()                                              zCall( 0x005F5140 );
    virtual unsigned short* GetIndexListPtr()                                             zCall( 0x005F5150 );

    // static properties
    static unsigned long& s_classCtorCtr;
  };

  class zCVertexBufferDyn {
  public:
    enum LOCK_FLAGS {
      LOCKFLAGS_FLUSH  = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_DISCARDCONTENTS,
      LOCKFLAGS_APPEND = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_NOOVERWRITE
    };

    zCVertexBuffer* vertexBuffer;
    unsigned long vertexFormat;
    unsigned long numVert;
    unsigned long vertexSizeBytes;
    unsigned long currentPos;
    int locked;
    int flush;

    zCVertexBufferDyn() {}
    void zCVertexBufferDyn_OnInit( unsigned long, unsigned long ) zCall( 0x005F54D0 );
    zCVertexBufferDyn( unsigned long a0, unsigned long a1 )       zInit( zCVertexBufferDyn_OnInit( a0, a1 ));
    ~zCVertexBufferDyn()                                          zCall( 0x005F5520 );
    void* Lock( unsigned long, unsigned long& )                   zCall( 0x005F5560 );
    void Unlock()                                                 zCall( 0x005F55E0 );
  };

  class zCVertexBufferDyn2 {
  public:
    enum LOCK_FLAGS {
      LOCKFLAGS_FLUSH  = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_DISCARDCONTENTS,
      LOCKFLAGS_APPEND = zVBUFFER_LOCK_FLAG_NOSYSLOCK | zVBUFFER_LOCK_FLAG_WRITEONLY | zVBUFFER_LOCK_FLAG_NOOVERWRITE
    };

    zCVertexBuffer* vertexBuffer;
    unsigned long vertexFormat;
    unsigned long numVert;
    unsigned long vertexSizeBytes;
    unsigned long currentPos;
    int locked;
    int flush;

    zCVertexBufferDyn2() {}
    void zCVertexBufferDyn2_OnInit( unsigned long, unsigned long ) zCall( 0x005F5600 );
    zCVertexBufferDyn2( unsigned long a0, unsigned long a1 )       zInit( zCVertexBufferDyn2_OnInit( a0, a1 ));
    ~zCVertexBufferDyn2()                                          zCall( 0x005F5650 );
    void ReserveVerts( unsigned long )                             zCall( 0x005F56A0 );
    void* Lock( unsigned long& )                                   zCall( 0x005F56C0 );
    void Unlock( unsigned long )                                   zCall( 0x005F5720 );
  };

  class zCVertexBufferManager {
  public:
    zCArray<zCVertexBuffer*> openVBList;
    zCArray<zCVertexBuffer*> closedVBList;
    int changeWorldHintSet;

    void zCVertexBufferManager_OnInit()                                                                     zCall( 0x005F5780 );
    zCVertexBufferManager()                                                                                 zInit( zCVertexBufferManager_OnInit() );
    ~zCVertexBufferManager()                                                                                zCall( 0x005F57B0 );
    zCVertexBuffer* AcquireVertexBuffer( unsigned long, unsigned long, unsigned long, unsigned long, int& ) zCall( 0x005F5810 );
    int ReleaseVertexBuffer( zCVertexBuffer* )                                                              zCall( 0x005F5B80 );
    void UnlockOpenVertexBuffers()                                                                          zCall( 0x005F5C40 );
    void StartChangeWorld()                                                                                 zCall( 0x005F5E40 );
    void EndChangeWorld()                                                                                   zCall( 0x005F5E50 );
  };

} // namespace Gothic_II_Classic

#endif // __ZVERTEX_BUFFER_H__VER2__