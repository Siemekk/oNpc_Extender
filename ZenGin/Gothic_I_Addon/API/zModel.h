// Supported with union (c) 2018 Union team

#ifndef __ZMODEL_H__VER1__
#define __ZMODEL_H__VER1__

namespace Gothic_I_Addon {
  const float zMDL_ANI_BLEND_IN_ZERO   = float_MAX;
  const float zMDL_ANI_BLEND_OUT_ZERO  =-float_MAX;
  const int zMDL_ANIEVENT_MAXSTRING    = 4;
  const int zMAN_VERS                  = 12;
  const int zMDL_MAX_ANIS_PARALLEL     = 6;
  const int zMDL_MAX_MESHLIBS_PARALLEL = 4;
  const int zMDL_VELRING_SIZE          = 8;
  const int MAX_ANIHISTORY             = 16;

  enum zTMdl_AniDir {
    zMDL_ANIDIR_FORWARD,
    zMDL_ANIDIR_REVERSE,
    zMDL_ANIDIR_ENDFASTEST
  };

  enum zTMdl_AniEventType {
    zMDL_EVENT_TAG,
    zMDL_EVENT_SOUND,
    zMDL_EVENT_SOUND_GRND,
    zMDL_EVENT_ANIBATCH,
    zMDL_EVENT_SWAPMESH,
    zMDL_EVENT_HEADING,
    zMDL_EVENT_PFX,
    zMDL_EVENT_PFX_GRND,
    zMDL_EVENT_PFX_STOP,
    zMDL_EVENT_SETMESH,
    zMDL_EVENT_MM_STARTANI,
    zMDL_EVENT_CAM_TREMOR
  };

  enum zTMdl_AniType {
    zMDL_ANI_TYPE_NORMAL,
    zMDL_ANI_TYPE_BLEND,
    zMDL_ANI_TYPE_SYNC,
    zMDL_ANI_TYPE_ALIAS,
    zMDL_ANI_TYPE_BATCH,
    zMDL_ANI_TYPE_COMB,
    zMDL_ANI_TYPE_DISABLED
  };

  enum zTModelProtoImportMAXFlags {
    zMDL_MAX_IMPORT_ANI         = 1,
    zMDL_MAX_IMPORT_MESH        = 2,
    zMDL_MAX_IMPORT_TREE        = 4,
    zMDL_MAX_IMPORT_PASS_ZCMESH = 8,
    zMDL_MAX_IMPORT_NO_LOD      = 16
  };

  class zCModelMeshLib : public zCObject {
  public:
    zCLASS_DECLARATION( zCModelMeshLib )

    struct zTNodeMesh {
    public:
      zCVisual* visual;
      int nodeIndex;
    };

    zCArray<zTNodeMesh> meshNodeList;
    zCArray<zCMeshSoftSkin*> meshSoftSkinList;

    void zCModelMeshLib_OnInit()                                                            zCall( 0x00599D60 );
    zCModelMeshLib()                                                                        zInit( zCModelMeshLib_OnInit() );
    void ReleaseData()                                                                      zCall( 0x00599F10 );
    void AllocNumNodeVisuals( int )                                                         zCall( 0x00599F80 );
    void AddMeshSoftSkin( zCMeshSoftSkin* )                                                 zCall( 0x0059A000 );
    void AddNodeVisual( int, zCVisual* )                                                    zCall( 0x0059A100 );
    void ApplyToModel( zCModel* )                                                           zCall( 0x0059A220 );
    void ApplyToModel( zCModelPrototype* )                                                  zCall( 0x0059A380 );
    void RemoveFromModel( zCModel* )                                                        zCall( 0x0059A500 );
    void BuildFromModel( zCModelPrototype* )                                                zCall( 0x0059A5F0 );
    void BuildFromModel( zCModel* )                                                         zCall( 0x0059A800 );
    void SaveMDM( zCModelPrototype* )                                                       zCall( 0x0059AA50 );
    void SaveMDM( zCFileBIN&, zCModelPrototype* )                                           zCall( 0x0059AC90 );
    static void operator delete( void*, char const*, char const*, int )                     zCall( 0x0057D2F0 );
    static zCObject* _CreateNewInstance()                                                   zCall( 0x00582E60 );
    static void* operator new( unsigned int, char const*, char const*, int )                zCall( 0x00599D20 );
    static unsigned long GetMDMFileVersion()                                                zCall( 0x0059AA20 );
    static int LoadMDM( zSTRING const&, zCModelPrototype*, zCModel*, zCModelMeshLib** )     zCall( 0x0059B130 );
    static int LoadMDM_Try( zSTRING const&, zCModelPrototype*, zCModel*, zCModelMeshLib** ) zCall( 0x0059B4A0 );
    static int LoadMDM( zCFileBIN&, zCModelPrototype*, zCModel*, zCModelMeshLib** )         zCall( 0x0059B6B0 );
    static int ConvertMDM( zSTRING const&, zCModelPrototype* )                              zCall( 0x0059C360 );
    virtual zCClassDef* _GetClassDef() const                                                zCall( 0x0057D310 );
    virtual ~zCModelMeshLib()                                                               zCall( 0x00599E30 );
  };

  class zCModelAniEvent {
  public:

    zTMdl_AniEventType aniEventType;
    int frameNr;
    zSTRING tagString;
    zSTRING string[zMDL_ANIEVENT_MAXSTRING];
    float value1;
    float value2;
    float value3;
    float value4;
    zCArray<zCSoundFX*> soundList;
    zCArray<zCParticleEmitter*> pfxEmitterList;

    void zCModelAniEvent_OnInit() zCall( 0x00586DB0 );
    zCModelAniEvent()             zInit( zCModelAniEvent_OnInit() );
    ~zCModelAniEvent()            zCall( 0x00586E50 );
    void Save( zCFileBIN& ) const zCall( 0x00586F40 );
    void Load( zCFileBIN& )       zCall( 0x005870A0 );
  };

  class zCModelNode {
  public:
    zCModelNode* parentNode;
    zSTRING nodeName;
    zCVisual* visual;
    zMAT4 trafo;
    zVEC3 nodeRotAxis;
    float nodeRotAngle;
    zVEC3 translation;
    zMAT4 trafoObjToWorld;
    zMAT4* nodeTrafoList;
    zCModelNodeInst* lastInstNode;

    void zCModelNode_OnInit()                     zCall( 0x00582FD0 );
    void zCModelNode_OnInit( zCModelNode const& ) zCall( 0x00583110 );
    zCModelNode()                                 zInit( zCModelNode_OnInit() );
    zCModelNode( zCModelNode const& a0 )          zInit( zCModelNode_OnInit( a0 ));
    ~zCModelNode()                                zCall( 0x005832A0 );
    void SetNodeVisualS( zCVisual* )              zCall( 0x00583350 );
  };

#pragma pack( push, 1 )
  struct zTMdl_AniSample {
  public:
    unsigned short rotation[3];
    unsigned short position[3];
  };
#pragma pack( pop )

  class zCModelAni : public zCObject {
  public:
    zCLASS_DECLARATION( zCModelAni )

    enum {
      zMDL_ANI_FLAG_VOB_ROT  = 1,
      zMDL_ANI_FLAG_VOB_POS  = 2,
      zMDL_ANI_FLAG_END_SYNC = 4,
      zMDL_ANI_FLAG_FLY      = 8,
      zMDL_ANI_FLAG_IDLE     = 16
    };

    zSTRING aniName;
    zSTRING ascName;
    int aniID;
    zSTRING aliasName;
    zCList<zCModelAni> combAniList;
    int layer;
    float blendInSpeed;
    float blendOutSpeed;
    zTBBox3D aniBBox3DObjSpace;
    float collisionVolumeScale;
    zCModelAni* nextAni;
    zSTRING nextAniName;
    zCModelAniEvent* aniEvents;
    float fpsRate;
    float fpsRateSource;
    int rootNodeIndex;
    zCArray<int> nodeIndexList;
    zCModelNode** nodeList;
    zTMdl_AniSample* aniSampleMatrix;
    float samplePosRangeMin;
    float samplePosScaler;
    group {
      int numFrames         : 16;
      int numNodes          : 16;
      zTMdl_AniType aniType : 6;
      zTMdl_AniDir aniDir   : 2;
      int numAniEvents      : 6;
    };
    group {
      byte flagVobRot      : 1;
      byte flagVobPos      : 1;
      byte flagEndSync     : 1;
      byte flagFly         : 1;
      byte flagIdle        : 1;
      byte flagInPlace     : 1;
      byte flagStaticCycle : 1;
	}
    aniFlags;

    void zCModelAni_OnInit()                                            zCall( 0x00583750 );
    zCModelAni()                                                        zInit( zCModelAni_OnInit() );
    void PrecacheAniEventData()                                         zCall( 0x00583B90 );
    float GetAniVelocity() const                                        zCall( 0x00583C60 );
    zVEC3 GetAniTranslation() const                                     zCall( 0x00583DF0 );
    void AddTrafoMatrix( zMAT4** )                                      zCall( 0x00583F60 );
    zCQuat GetQuat( int, int ) const                                    zCall( 0x005844A0 );
    zVEC3 GetTrans( int, int ) const                                    zCall( 0x00584500 );
    void SetTrans( int, int, zVEC3 const& )                             zCall( 0x005845B0 );
    void SetQuat( int, int, zCQuat const& )                             zCall( 0x00584630 );
    void AddNodeList( zCTree<zCModelNode>** )                           zCall( 0x005846D0 );
    void SetFlags( zSTRING const& )                                     zCall( 0x00584750 );
    void SetBlendingSec( float, float )                                 zCall( 0x00584800 );
    void GetBlendingSec( float&, float& ) const                         zCall( 0x00584860 );
    void CorrectRootNodeIdleMovement()                                  zCall( 0x005848C0 );
    void CalcInPlaceFlag()                                              zCall( 0x00584A30 );
    int ResolveAlias( zCModelPrototype* )                               zCall( 0x00584C10 );
    int ResolveComb( zCModelPrototype* )                                zCall( 0x00584F50 );
    void SaveMAN( zCModelPrototype*, zSTRING const& )                   zCall( 0x00585720 );
    int LoadMAN( zSTRING const&, zCModelPrototype*, zSTRING const& )    zCall( 0x005860D0 );
    zSTRING const& GetAniName() const                                   zCall( 0x00598B90 );
    zTMdl_AniType GetAniType() const                                    zCall( 0x00598BA0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00575580 );
    static void operator delete( void*, char const*, char const*, int ) zCall( 0x005755F0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005838F0 );
    virtual ~zCModelAni()                                               zCall( 0x00583930 );
  };

  class zCModelPrototype {
  public:
    enum zTFileSourceType {
      zFROM_MDS,
      zFROM_ASC
    };

    zCModelPrototype* next;
    zCModelPrototype* prev;
    int refCtr;
    zSTRING modelProtoName;
    zSTRING modelProtoFileName;
    zCTree<zCModelNode> meshTree;
    zCArraySort<zCModelAni*> protoAnis;
    zCArray<zCModelAniEvent*> modelEvents;
    zCArray<zCModelNode*> nodeList;
    unsigned long nodeListChecksum;
    zCArray<zCMeshSoftSkin*> meshSoftSkinList;
    zSTRING hierarchySourceASC;
    zTBBox3D bbox3D;
    zTBBox3D bbox3DCollDet;
    zCModelPrototype* baseModelProto;
    zVEC3 rootNodeTrans;
    zTFileSourceType fileSourceType;
    zCArray<zCMesh*> sourceMeshSoftSkinList;

    void zCModelPrototype_OnInit()                                                           zCall( 0x00587150 );
    zCModelPrototype()                                                                       zInit( zCModelPrototype_OnInit() );
    void Init()                                                                              zCall( 0x005873A0 );
    ~zCModelPrototype()                                                                      zCall( 0x005875A0 );
    void Clear()                                                                             zCall( 0x00587800 );
    void ReleaseMeshSoftSkinList()                                                           zCall( 0x005879A0 );
    void ReleaseMeshes()                                                                     zCall( 0x00587A00 );
    int Release()                                                                            zCall( 0x00587A90 );
    zSTRING const& GetModelProtoFileName() const                                             zCall( 0x00587AE0 );
    void SetModelProtoName( zSTRING const& )                                                 zCall( 0x00587AF0 );
    void SetFileSourceType( zTFileSourceType )                                               zCall( 0x00587C90 );
    int PrepareAsModelProtoOverlay( zCModelPrototype* )                                      zCall( 0x00588070 );
    void CalcNodeListChecksum()                                                              zCall( 0x005884B0 );
    void CollectNodeMeshes( zCArray<zCModelNode*>& )                                         zCall( 0x00588510 );
    zCModelNode* SearchNode( zSTRING const& )                                                zCall( 0x00588770 );
    zCTree<zCModelNode>* FindMeshTreeNode( zSTRING const&, zCTree<zCModelNode>* )            zCall( 0x00588820 );
    int FindMeshTreeNodeIndex( zSTRING const&, zCTree<zCModelNode>* )                        zCall( 0x005888C0 );
    int FindNodeListIndex( zSTRING const& )                                                  zCall( 0x00588980 );
    void AddAni( zCModelAni* )                                                               zCall( 0x00588A20 );
    int __fastcall SearchAniIndex( zSTRING const& ) const                                    zCall( 0x00588C60 );
    zCModelAni* SearchAni( zSTRING const& ) const                                            zCall( 0x00588D30 );
    void DescribeTree( zCTree<zCModelNode>*, int )                                           zCall( 0x00588D50 );
    int LoadMDH( zSTRING const& )                                                            zCall( 0x00588FD0 );
    int LoadMDH( zCFileBIN& )                                                                zCall( 0x00589250 );
    void SaveMDH()                                                                           zCall( 0x005899A0 );
    void SaveMDH( zCFileBIN& )                                                               zCall( 0x00589BD0 );
    void ConvertVec3( zVEC3& )                                                               zCall( 0x0058A0F0 );
    void ConvertAngle( float& )                                                              zCall( 0x0058A110 );
    void SkipBlock()                                                                         zCall( 0x0058A120 );
    void SkipBlockCmt()                                                                      zCall( 0x0058A1A0 );
    void ReadComment()                                                                       zCall( 0x0058A2A0 );
    void ReadScene( float& )                                                                 zCall( 0x0058A2B0 );
    zVEC3 ReadTriple()                                                                       zCall( 0x0058A680 );
    zMAT4 ReadNodeTM( zCModelNode* )                                                         zCall( 0x0058A8B0 );
    void ReadVertexList( zCMesh*, int )                                                      zCall( 0x0058AD80 );
    zTMatIDList* ReadFaceList( zCMesh*, int )                                                zCall( 0x0058B000 );
    zVEC2* ReadTVertexList( int )                                                            zCall( 0x0058B5A0 );
    void ReadTFaceList( zCMesh*, zVEC2*, int )                                               zCall( 0x0058B7F0 );
    void ReadSoftSkinVertList()                                                              zCall( 0x0058BA90 );
    zCMesh* ReadMesh( int, zCModelNode*, int )                                               zCall( 0x0058CDA0 );
    void ReadMeshAnimation( zCModelNode*, int )                                              zCall( 0x0058D1C0 );
    void ReadPosTrack( zMAT4* )                                                              zCall( 0x0058D340 );
    void ReadRotTrack( zMAT4* )                                                              zCall( 0x0058D550 );
    void ReadTMAnimation( zCModelNode*, zMAT4*& )                                            zCall( 0x0058D850 );
    void LocalizeTrafos( zCTree<zCModelNode>*, zCTree<zCModelNode>* )                        zCall( 0x0058DF50 );
    void ReadMapDiffuse( zCMaterial* )                                                       zCall( 0x0058E0B0 );
    zCMaterial* ReadMaterial()                                                               zCall( 0x0058E530 );
    zCMaterial* ReadWireframeColor()                                                         zCall( 0x0058EC00 );
    void AssignMeshNodeMaterials( zCMesh*, zTMatIDList*, int )                               zCall( 0x0058EEE0 );
    void TransformNodeVisual( zCModelNode*, zMAT4 const& )                                   zCall( 0x0058EFF0 );
    void ProcessMeshNode( zCModelNode*, zCTree<zCModelNode>*, int, int, int& )               zCall( 0x0058F040 );
    void ReadGeomobject( zMAT4*&, zCTree<zCModelNode>*& )                                    zCall( 0x0058F470 );
    void ReadMaterialList()                                                                  zCall( 0x00590B50 );
    void Load3DSMAXAsc( zCModelAni*&, zSTRING const&, zSTRING const&, int, int, int, float ) zCall( 0x00590DF0 );
    void CalcAniBBox( zCModelAni* )                                                          zCall( 0x00591E80 );
    void ResolveReferences()                                                                 zCall( 0x00592450 );
    void SkipBlockMDS( int )                                                                 zCall( 0x00592760 );
    void ReadMeshAndTree( int& )                                                             zCall( 0x005927E0 );
    void RegisterMesh()                                                                      zCall( 0x00592CF0 );
    void ReadStartMesh()                                                                     zCall( 0x00592F60 );
    void ReadAniEventTag( zSTRING&, zCModelAniEvent* )                                       zCall( 0x00593110 );
    void ReadAniEnum( int )                                                                  zCall( 0x005933E0 );
    void ReadModel()                                                                         zCall( 0x00598C60 );
    int LoadModelScript( zSTRING const& )                                                    zCall( 0x00598DC0 );
    int LoadModelASC( zSTRING const& )                                                       zCall( 0x005993E0 );
    static int NumInList()                                                                   zCall( 0x00587AC0 );
    static zCModelPrototype* Load( zSTRING const&, zCModelPrototype* )                       zCall( 0x00587E10 );
    static zCModelPrototype* SearchName( zSTRING )                                           zCall( 0x00588690 );
    static unsigned long GetMDHFileVersion()                                                 zCall( 0x00588FC0 );

    // static properties
    static int& s_ignoreAnis;
    static int& s_autoConvertAnis;
    static int& s_autoConvertMeshes;
    static zCModelPrototype*& s_modelRoot;
  };

  class zCModelAniActive {
  public:
    zCModelAni* protoAni;
    zCModelAni* nextAni;
    int advanceDir;
    float actFrame;
    int actAniEvent;
    float combAniX;
    float combAniY;
    int isFadingOut;
    int isFirstTime;
    zCModelAni* nextAniOverride;
    float blendInOverride;
    float blendOutOverride;
    zVEC3 lastPos;
    zVEC3 thisPos;
    zCQuat lastRotQuat;
    zCQuat thisRotQuat;
    zCQuat freezeRotQuat;
    int rotFirstTime;
    float transWeight;
    zTAniAttachment* aniAttachment;
    float randAniTimer;

    void zCModelAniActive_OnInit()          zCall( 0x00575710 );
    zCModelAniActive()                      zInit( zCModelAniActive_OnInit() );
    ~zCModelAniActive()                     zCall( 0x00575800 );
    void SetDirection( zTMdl_AniDir )       zCall( 0x00575820 );
    float GetProgressPercent() const        zCall( 0x00575870 );
    void SetProgressPercent( float )        zCall( 0x005758B0 );
    void SetActFrame( float )               zCall( 0x00575900 );
    void DoCombineAni( zCModel*, int, int ) zCall( 0x0057E780 );
  };

  class zCModelTexAniState {
  public:
    enum {
      zMDL_MAX_ANI_CHANNELS = 2,
      zMDL_MAX_TEX          = 4
    };

    int numNodeTex;
    zCTexture** nodeTexList;
    int actAniFrames[zMDL_MAX_ANI_CHANNELS][zMDL_MAX_TEX];

    void zCModelTexAniState_OnInit()                                      zCall( 0x00575950 );
    zCModelTexAniState()                                                  zInit( zCModelTexAniState_OnInit() );
    ~zCModelTexAniState()                                                 zCall( 0x00575970 );
    void DeleteTexList()                                                  zCall( 0x00575990 );
    void UpdateTexList()                                                  zCall( 0x005759B0 );
    void SetChannelVariation( int, int, zSTRING* )                        zCall( 0x005759F0 );
    void BuildTexListFromMeshLib( zCModelMeshLib* )                       zCall( 0x00575A60 );
    void BuildTexListFromMesh( zCMesh* )                                  zCall( 0x00575AE0 );
    void BuildTexListFromProgMesh( zCProgMeshProto* )                     zCall( 0x00575C00 );
    void AddTexListFromMeshLib( zCModelMeshLib*, zCArray<zCTexture*>& )   zCall( 0x00575D70 );
    void AddTexListFromMesh( zCMesh*, zCArray<zCTexture*>& )              zCall( 0x00575FF0 );
    void AddTexListFromProgMesh( zCProgMeshProto*, zCArray<zCTexture*>& ) zCall( 0x00576170 );
    void FinishTexList( zCArray<zCTexture*>& )                            zCall( 0x005762E0 );
  };

#pragma pack( push, 1 )
  class zCModelNodeInst {
  public:
    enum {
      zMDL_BLEND_STATE_FADEIN,
      zMDL_BLEND_STATE_CONST,
      zMDL_BLEND_STATE_FADEOUT
    };

    struct zTNodeAni {
      zCModelAniActive* modelAni;
      float weight;
      float weightSpeed;
      int blendState;
      zCQuat quat;

      zTNodeAni() {}
    };

    zCModelNodeInst* parentNode;
    zCModelNode* protoNode;
    zCVisual* nodeVisual;
    zMAT4 trafo;
    zMAT4 trafoObjToCam;
    zTBBox3D bbox3D;
    zCModelTexAniState texAniState;
    zTNodeAni nodeAniList[zMDL_MAX_ANIS_PARALLEL];
    int numNodeAnis;
    int masterAni;
    float masterAniSpeed;

    void zCModelNodeInst_OnInit()                            zCall( 0x00576430 );
    void zCModelNodeInst_OnInit( zCModelNode* )              zCall( 0x00576500 );
    zCModelNodeInst()                                        zInit( zCModelNodeInst_OnInit() );
    zCModelNodeInst( zCModelNode* a0 )                       zInit( zCModelNodeInst_OnInit( a0 ));
    ~zCModelNodeInst()                                       zCall( 0x005765F0 );
    void Init()                                              zCall( 0x00576670 );
    void InitByModelProtoNode( zCModelNode* )                zCall( 0x00576700 );
    void SetNodeVisualS( zCVisual*, int )                    zCall( 0x005767B0 );
    void AddNodeAni( zCModelAniActive* )                     zCall( 0x0057D3D0 );
    void RemoveAllNodeAnis()                                 zCall( 0x0057D620 );
    void RemoveNodeAni( zCModelAniActive* )                  zCall( 0x0057D630 );
    void FindMasterAni()                                     zCall( 0x0057D720 );
    void FadeOutNodeAni( zCModelAniActive* )                 zCall( 0x0057D790 );
    void CalcWeights( zCModel* )                             zCall( 0x0057DD70 );
    void AddToNodeAniWeight( int, float )                    zCall( 0x0057DFC0 );
    void CalcBlending( zCModel* )                            zCall( 0x0057E030 );
    int GetNodeAniListIndex( zCModelAniActive const* ) const zCall( 0x0057E1B0 );
  };
#pragma pack( pop )

  struct zTRandAni {
    int randAniProtoID;
    int prob;

    zTRandAni() {}
  };

  struct zTAniAttachment {
    int aniID;
    zCArray<zTRandAni> randAniList;
    float randAniFreq;
    int randAniProbSum;

    void zTAniAttachment_OnInit() zCall( 0x00581870 );
    ~zTAniAttachment()            zCall( 0x00581850 );
    zTAniAttachment()             zInit( zTAniAttachment_OnInit() );
  };

  class zCModel : public zCVisualAnimate {
  public:
    zCLASS_DECLARATION( zCModel )

    enum {
      zMDL_DYNLIGHT_SCALEPRELIT = 0,
      zMDL_DYNLIGHT_EXACT       = 1
    };

    enum {
      zMDL_STARTANI_DEFAULT,
      zMDL_STARTANI_ISNEXTANI,
      zMDL_STARTANI_FORCE
    };

    struct zTMdl_NodeVobAttachment {
    public:
      zCVob* vob;
      zCModelNodeInst* mnode;
    };

    struct zTMdl_StartedVobFX {
    public:
      zCVob* vob;
      float vobFXHandle;
    };

    struct zTAniMeshLibEntry {
    public:
      zCModelAniActive* ani;
      zCModelMeshLib* meshLib;
    };

    struct zTMeshLibEntry {
    public:
      zCModelTexAniState texAniState;
      zCModelMeshLib* meshLib;
    };

    int numActiveAnis;
    zCModelAniActive* aniChannels[zMDL_MAX_ANIS_PARALLEL];
    zCModelAniActive* activeAniList;
    zCVob* homeVob;
    zCArray<zCModelPrototype*> modelProtoList;
    zCArray<zCModelNodeInst*> nodeList;
    zCArray<zCMeshSoftSkin*> meshSoftSkinList;
    zCArraySort<zTAniAttachment*> aniAttachList;
    zCArray<zTMdl_NodeVobAttachment>attachedVobList;
    zCArray<zTMdl_StartedVobFX> startedVobFX;
    zCArray<zTAniMeshLibEntry> aniMeshLibList;
    zCArray<zTMeshLibEntry*> meshLibList;
    int lastTimeBBox3DTreeUpdate;
    zCArray<zCModelAniEvent*> occuredAniEvents;
    zTBBox3D bbox3D;
    zTBBox3D bbox3DLocalFixed;
    zTBBox3D bbox3DCollDet;
    float modelDistanceToCam;
    float fatness;
    zVEC3 modelScale;
    zVEC3 aniTransScale;
    zVEC3 rootPosLocal;
    zVEC3 vobTrans;
    zCQuat vobRot;
    zVEC3 modelVelocity;
    int actVelRingPos;
    zVEC3 modelVelRing[zMDL_VELRING_SIZE];
    group {
      unsigned char isVisible         : 1;
      unsigned char isFlying          : 1;
      unsigned char randAnisEnabled   : 1;
      unsigned char lerpSamples       : 1;
      unsigned char modelScaleOn      : 1;
      unsigned char doVobRot          : 1;
      unsigned char nodeShadowEnabled : 1;
      unsigned char dynLightMode      : 1;
    };
    float timeScale;
    zCModelAni** aniHistoryList;

    zCModel() {}
    void zCModel_OnInit( zCModelPrototype* )                                                                        zCall( 0x00576D90 );
    zCModelAni* GetAniFromAniID( int ) const                                                                        zCall( 0x00475680 );
    int IsAniActive( zCModelAni* )                                                                                  zCall( 0x004756D0 );
    int GetAniIDFromAniName( zSTRING const& ) const                                                                 zCall( 0x00489660 );
    void Init()                                                                                                     zCall( 0x00576B60 );
    zCModel( zCModelPrototype* a0 )                                                                                 zInit( zCModel_OnInit( a0 ));
    void CopyProtoNodeList()                                                                                        zCall( 0x00576F30 );
    int ApplyModelProtoOverlay( zSTRING const& )                                                                    zCall( 0x00577340 );
    int ApplyModelProtoOverlay( zCModelPrototype* )                                                                 zCall( 0x00577390 );
    int HasAppliedModelProtoOverlay( zCModelPrototype* ) const                                                      zCall( 0x005775A0 );
    int HasAppliedModelProtoOverlay( zSTRING const& ) const                                                         zCall( 0x005775D0 );
    void RemoveModelProtoOverlay( zSTRING const& )                                                                  zCall( 0x00577780 );
    void RemoveModelProtoOverlay( zCModelPrototype* )                                                               zCall( 0x005779A0 );
    void CalcNodeListBBoxWorld()                                                                                    zCall( 0x00577B20 );
    zTBBox3D GetBBox3DNodeWorld( zCModelNodeInst* )                                                                 zCall( 0x00577C60 );
    zVEC3 GetNodePositionWorld( zCModelNodeInst* )                                                                  zCall( 0x00577CD0 );
    void CalcModelBBox3DWorld()                                                                                     zCall( 0x00577D10 );
    void SetNodeVisual( zCModelNodeInst*, zCVisual*, int )                                                          zCall( 0x00577E20 );
    void SetDynLightMode( int )                                                                                     zCall( 0x00577E50 );
    void __fastcall RenderNodeList( zTRenderContext&, zCArray<zMAT4*>&, zCRenderLightContainer&, zTPMLightingMode ) zCall( 0x00577E70 );
    void CheckNodeCollisionList( zCOBBox3D const&, zMAT4& )                                                         zCall( 0x00578E70 );
    void CheckNodeCollision( zCModel*, zCModelNodeInst*, zMAT4&, zCList<zCModelNodeInst>& )                         zCall( 0x00578F10 );
    zMAT4 GetTrafoNodeToModel( zCModelNodeInst* )                                                                   zCall( 0x00579080 );
    void SetRandAnisEnabled( int )                                                                                  zCall( 0x005791B0 );
    zCModelAniActive* GetActiveAni( int ) const                                                                     zCall( 0x00579220 );
    zCModelAniActive* GetActiveAni( zCModelAni* ) const                                                             zCall( 0x00579260 );
    void StopAni( int )                                                                                             zCall( 0x005792A0 );
    void StopAni( zCModelAni* )                                                                                     zCall( 0x00579320 );
    void StopAni( zCModelAniActive* )                                                                               zCall( 0x00579370 );
    zVEC3 GetAniTransLerp( zCModelAni*, float, int ) const                                                          zCall( 0x00579550 );
    void StartAni( zSTRING const&, int )                                                                            zCall( 0x005796F0 );
    void StartAni( int, int )                                                                                       zCall( 0x00579960 );
    void StartAni( zCModelAni*, int )                                                                               zCall( 0x005799D0 );
    void AssertActiveAniListAlloced()                                                                               zCall( 0x0057A0C0 );
    void DoAniEvents( zCModelAniActive* )                                                                           zCall( 0x0057A1F0 );
    void __fastcall AdvanceAni( zCModelAniActive*, int& )                                                           zCall( 0x0057B150 );
    void AdvanceAnis()                                                                                              zCall( 0x0057B430 );
    void SetModelScale( zVEC3 const& )                                                                              zCall( 0x0057C430 );
    int IsStateActive( zCModelAni const* ) const                                                                    zCall( 0x0057C5B0 );
    zCModelNodeInst* SearchNode( zSTRING const& )                                                                   zCall( 0x0057C810 );
    int SetNodeMeshTexture( zSTRING const&, int, int, zSTRING* )                                                    zCall( 0x0057C8C0 );
    int SetMeshLibTexture( zSTRING const&, int, int, zSTRING* )                                                     zCall( 0x0057C9E0 );
    void RemoveMeshLibAll()                                                                                         zCall( 0x0057CC20 );
    int RemoveMeshLib( zSTRING const& )                                                                             zCall( 0x0057CC50 );
    int ApplyMeshLib( zSTRING const& )                                                                              zCall( 0x0057CEA0 );
    void UpdateMeshLibTexAniState()                                                                                 zCall( 0x0057D350 );
    void FadeOutAni( int )                                                                                          zCall( 0x0057D850 );
    void FadeOutAni( zCModelAni* )                                                                                  zCall( 0x0057D8D0 );
    void FadeOutAni( zCModelAniActive* )                                                                            zCall( 0x0057D910 );
    void FadeOutAnisLayerRange( int, int )                                                                          zCall( 0x0057DAE0 );
    void StopAnisLayerRange( int, int )                                                                             zCall( 0x0057DB30 );
    float GetProgressPercent( zSTRING const& ) const                                                                zCall( 0x0057DB80 );
    float GetProgressPercent( int ) const                                                                           zCall( 0x0057DC40 );
    void SetCombineAniXY( int, float, float ) const                                                                 zCall( 0x0057DCB0 );
    int GetCombineAniXY( int, float&, float& ) const                                                                zCall( 0x0057DD00 );
    void CalcNodeListAniBlending()                                                                                  zCall( 0x0057E180 );
    void CalcTransBlending()                                                                                        zCall( 0x0057E1E0 );
    void AttachChildVobToNode( zCVob*, zCModelNodeInst* )                                                           zCall( 0x0057F0D0 );
    void RemoveChildVobFromNode( zCVob* )                                                                           zCall( 0x0057F260 );
    void RemoveAllChildVobsFromNode()                                                                               zCall( 0x0057F2E0 );
    void UpdateAttachedVobs()                                                                                       zCall( 0x0057F330 );
    void RemoveStartedVobFX( zCVob* )                                                                               zCall( 0x0057F480 );
    void RemoveAllVobFX()                                                                                           zCall( 0x0057F530 );
    zVEC3 GetVelocityRing() const                                                                                   zCall( 0x0057F5C0 );
    void ResetVelocity()                                                                                            zCall( 0x0057F630 );
    void GetAniMinMaxWeight( zCModelAniActive*, float&, float& )                                                    zCall( 0x0057F6C0 );
    void PrintStatus( int, int )                                                                                    zCall( 0x0057F910 );
    void psb_WriteAniBlock( zCBuffer&, int, int ) const                                                             zCall( 0x00580010 );
    void psb_ReadAniBlock( zCBuffer&, int, zCModelAniActive* )                                                      zCall( 0x005801A0 );
    void PackStateBinary( zCBuffer& )                                                                               zCall( 0x00580410 );
    void UnpackStateBinary( zCBuffer& )                                                                             zCall( 0x00580770 );
    void ShowAniListAdd( zCModelAni* )                                                                              zCall( 0x00580F60 );
    void ShowAniList( int )                                                                                         zCall( 0x00580FD0 );
    zTAniAttachment* SearchAniAttachList( int ) const                                                               zCall( 0x005818B0 );
    void RemoveAniAttachment( int )                                                                                 zCall( 0x00581950 );
    void RemoveAllAniAttachments()                                                                                  zCall( 0x00581AD0 );
    zTAniAttachment* GetCreateAniAttachment( int )                                                                  zCall( 0x00581B30 );
    void DeleteRandAniList( int )                                                                                   zCall( 0x00581D10 );
    void InsertRandAni( int, int, int )                                                                             zCall( 0x00581DB0 );
    float GetRandAniFreq( int ) const                                                                               zCall( 0x00581EE0 );
    void SetRandAniFreq( int, float )                                                                               zCall( 0x00581F80 );
    void __fastcall RecalcRootPosLocal( int )                                                                       zCall( 0x00581FA0 );
    static zCObject* _CreateNewInstance()                                                                           zCall( 0x00575020 );
    static void operator delete( void*, char const*, char const*, int )                                             zCall( 0x00575180 );
    static int AniAttachmentCompare( void const*, void const* )                                                     zCall( 0x00581880 );
    virtual zCClassDef* _GetClassDef() const                                                                        zCall( 0x005751A0 );
    virtual ~zCModel()                                                                                              zCall( 0x00576880 );
    virtual int Render( zTRenderContext& )                                                                          zCall( 0x00578BD0 );
    virtual int IsBBox3DLocal()                                                                                     zCall( 0x005751B0 );
    virtual zTBBox3D GetBBox3D()                                                                                    zCall( 0x0057C730 );
    virtual zSTRING GetVisualName()                                                                                 zCall( 0x0057C770 );
    virtual void SetVisualUsedBy( zCVob* )                                                                          zCall( 0x00577210 );
    virtual unsigned long GetRenderSortKey() const                                                                  zCall( 0x00581040 );
    virtual int CanTraceRay() const                                                                                 zCall( 0x005751C0 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                                      zCall( 0x00581060 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )                                                        zCall( 0x0057A140 );
    virtual zSTRING const* GetFileExtension( int )                                                                  zCall( 0x00577280 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                                                     zCall( 0x005772A0 );
    virtual void StartAnimation( zSTRING const& )                                                                   zCall( 0x005751D0 );
    virtual void StopAnimation( zSTRING const& )                                                                    zCall( 0x005751E0 );
    virtual int IsAnimationActive( zSTRING const& )                                                                 zCall( 0x00575280 );
    virtual zSTRING const* GetAnyAnimation()                                                                        zCall( 0x005794F0 );

    // static properties
    static int& s_drawSkeleton;
  };

  class zCModelConvertFileHandler : public zCScanDirFileHandler {
  public:

    void zCModelConvertFileHandler_OnInit()                            zCall( 0x0059C6C0 );
    zCModelConvertFileHandler()                                        zInit( zCModelConvertFileHandler_OnInit() );
    virtual ~zCModelConvertFileHandler()                               zCall( 0x00426AF0 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x0059C7F0 );
  };

} // namespace Gothic_I_Addon

#endif // __ZMODEL_H__VER1__