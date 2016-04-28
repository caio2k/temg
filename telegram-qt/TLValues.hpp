/*
   Copyright (C) 2014-2016 Alexandr Akulich <akulichalexander@gmail.com>

   This file is a part of TelegramQt library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

 */

#ifndef TLVALUE_HPP
#define TLVALUE_HPP

#include <QObject>

// TODO: Namespace?

struct TLValue {
    Q_GADGET
    Q_ENUMS(Value)
public:
    enum Value {
        // Generated TLValues (proto)
        ResPQ = 0x05162463,
        PQInnerData = 0x83c95aec,
        ServerDHParamsFail = 0x79cb045d,
        ServerDHParamsOk = 0xd0e8075c,
        ServerDHInnerData = 0xb5890dba,
        ClientDHInnerData = 0x6643b654,
        DhGenOk = 0x3bcbf734,
        DhGenRetry = 0x46dc1fb9,
        DhGenFail = 0xa69dae02,
        RpcResult = 0xf35c6d01,
        RpcError = 0x2144ca19,
        RpcAnswerUnknown = 0x5e2ad36e,
        RpcAnswerDroppedRunning = 0xcd78e586,
        RpcAnswerDropped = 0xa43ad8b7,
        FutureSalt = 0x0949d9dc,
        FutureSalts = 0xae500895,
        Pong = 0x347773c5,
        DestroySessionOk = 0xe22045fc,
        DestroySessionNone = 0x62d350c9,
        NewSessionCreated = 0x9ec20908,
        MsgContainer = 0x73f1f8dc,
        MsgCopy = 0xe06046b2,
        GzipPacked = 0x3072cfa1,
        MsgsAck = 0x62d6b459,
        BadMsgNotification = 0xa7eff811,
        BadServerSalt = 0xedab447b,
        MsgResendReq = 0x7d861a08,
        MsgsStateReq = 0xda69fb52,
        MsgsStateInfo = 0x04deb57d,
        MsgsAllInfo = 0x8cc0d131,
        MsgDetailedInfo = 0x276d3ec6,
        MsgNewDetailedInfo = 0x809db6df,
        ReqPq = 0x60469778,
        ReqDHParams = 0xd712e4be,
        SetClientDHParams = 0xf5045f1f,
        RpcDropAnswer = 0x58e4a740,
        GetFutureSalts = 0xb921bd04,
        Ping = 0x7abe77ec,
        PingDelayDisconnect = 0xf3427b8c,
        DestroySession = 0xe7512126,
        HttpWait = 0x9299359f,

        // End of generated TLValues (proto)

        // Generated TLValues
        // Types
        AccountAuthorizations = 0x1250abde,
        AccountDaysTTL = 0xb8d0afdf,
        AccountNoPassword = 0x96dabc18,
        AccountPassword = 0x7c18141c,
        AccountPasswordInputSettings = 0xbcfc532c,
        AccountPasswordSettings = 0xb7b72ab3,
        AccountPrivacyRules = 0x554abb6f,
        AccountSentChangePhoneCode = 0xa4f58c4c,
        AudioEmpty = 0x586988d8,
        Audio = 0xc7ac6496,
        AuthAuthorization = 0xf6b673a4,
        AuthCheckedPhone = 0x811ea28e,
        AuthExportedAuthorization = 0xdf969c2d,
        AuthPasswordRecovery = 0x137948a5,
        AuthSentCode = 0xefed51d9,
        AuthSentAppCode = 0xe325edcf,
        Authorization = 0x7bf2e6f6,
        ChatEmpty = 0x9ba2d800,
        Chat = 0x6e9c9bc7,
        ChatForbidden = 0xfb0ccc41,
        GeoChat = 0x75eaea5a,
        ChatFull = 0xcade0791,
        ChatInviteAlready = 0x5a686d7c,
        ChatInvite = 0xce917dcd,
        ChatLocated = 0x3631cf4c,
        ChatParticipant = 0xc8d7493e,
        ChatParticipantsForbidden = 0x0fd2bb8a,
        ChatParticipants = 0x7841b415,
        ChatPhotoEmpty = 0x37c1011c,
        ChatPhoto = 0x6153276a,
        Config = 0x4e32b894,
        Contact = 0xf911c994,
        ContactBlocked = 0x561bc879,
        ContactFound = 0xea879f95,
        ContactLinkUnknown = 0x5f4f9247,
        ContactLinkNone = 0xfeedd3ad,
        ContactLinkHasPhone = 0x268f3f59,
        ContactLinkContact = 0xd502c2d0,
        ContactStatus = 0xd3680c61,
        ContactSuggested = 0x3de191a1,
        ContactsBlocked = 0x1c138d15,
        ContactsBlockedSlice = 0x900802a1,
        ContactsContactsNotModified = 0xb74ba9d2,
        ContactsContacts = 0x6f8b8cb2,
        ContactsFound = 0x0566000e,
        ContactsImportedContacts = 0xad524315,
        ContactsLink = 0x3ace484c,
        ContactsSuggested = 0x5649dcc5,
        DcOption = 0x2ec2a43c,
        Dialog = 0xc1dd804a,
        DisabledFeature = 0xae636f24,
        DocumentEmpty = 0x36f8c871,
        Document = 0xf9a39f4f,
        DocumentAttributeImageSize = 0x6c37c15c,
        DocumentAttributeAnimated = 0x11b58939,
        DocumentAttributeSticker = 0x3a556302,
        DocumentAttributeVideo = 0x5910cccb,
        DocumentAttributeAudio = 0x051448e5,
        DocumentAttributeFilename = 0x15590068,
        EncryptedChatEmpty = 0xab7ec0a0,
        EncryptedChatWaiting = 0x3bf703dc,
        EncryptedChatRequested = 0xc878527e,
        EncryptedChat = 0xfa56ce36,
        EncryptedChatDiscarded = 0x13d6dd27,
        EncryptedFileEmpty = 0xc21f497e,
        EncryptedFile = 0x4a70994c,
        EncryptedMessage = 0xed18c118,
        EncryptedMessageService = 0x23734b06,
        Error = 0xc4b9f9bb,
        ChatInviteEmpty = 0x69df3769,
        ChatInviteExported = 0xfc2e05bc,
        FileLocationUnavailable = 0x7c596b46,
        FileLocation = 0x53d69076,
        GeoChatMessageEmpty = 0x60311a9b,
        GeoChatMessage = 0x4505f8e1,
        GeoChatMessageService = 0xd34fa24e,
        GeoPointEmpty = 0x1117dd5f,
        GeoPoint = 0x2049d70c,
        GeochatsLocated = 0x48feb267,
        GeochatsMessages = 0xd1526db1,
        GeochatsMessagesSlice = 0xbc5863e8,
        GeochatsStatedMessage = 0x17b1578b,
        HelpAppUpdate = 0x8987f311,
        HelpNoAppUpdate = 0xc45a6536,
        HelpInviteText = 0x18cb9f78,
        HelpSupport = 0x17c6b5f6,
        ImportedContact = 0xd0028438,
        InputAppEvent = 0x770656a8,
        InputAudioEmpty = 0xd95adc84,
        InputAudio = 0x77d440ff,
        InputChatPhotoEmpty = 0x1ca48f57,
        InputChatUploadedPhoto = 0x94254732,
        InputChatPhoto = 0xb2e1bf08,
        InputPhoneContact = 0xf392b7f4,
        InputDocumentEmpty = 0x72f0eaae,
        InputDocument = 0x18798952,
        InputEncryptedChat = 0xf141b5e1,
        InputEncryptedFileEmpty = 0x1837c364,
        InputEncryptedFileUploaded = 0x64bd0306,
        InputEncryptedFile = 0x5a17b5e5,
        InputEncryptedFileBigUploaded = 0x2dc173c8,
        InputFile = 0xf52ff27f,
        InputFileBig = 0xfa4f0bb5,
        InputFileLocation = 0x14637196,
        InputVideoFileLocation = 0x3d0364ec,
        InputEncryptedFileLocation = 0xf5235d55,
        InputAudioFileLocation = 0x74dc404d,
        InputDocumentFileLocation = 0x4e45abe9,
        InputGeoChat = 0x74d456fa,
        InputGeoPointEmpty = 0xe4c123d6,
        InputGeoPoint = 0xf3b7acc9,
        InputMediaEmpty = 0x9664f57f,
        InputMediaUploadedPhoto = 0xf7aff1c0,
        InputMediaPhoto = 0xe9bfb4f3,
        InputMediaGeoPoint = 0xf9c44144,
        InputMediaContact = 0xa6e45987,
        InputMediaUploadedVideo = 0xe13fd4bc,
        InputMediaUploadedThumbVideo = 0x96fb97dc,
        InputMediaVideo = 0x936a4ebd,
        InputMediaUploadedAudio = 0x4e498cab,
        InputMediaAudio = 0x89938781,
        InputMediaUploadedDocument = 0xffe76b78,
        InputMediaUploadedThumbDocument = 0x41481486,
        InputMediaDocument = 0xd184e841,
        InputMediaVenue = 0x2827a81a,
        InputNotifyPeer = 0xb8bc5b0c,
        InputNotifyUsers = 0x193b4417,
        InputNotifyChats = 0x4a95e84e,
        InputNotifyAll = 0xa429b886,
        InputNotifyGeoChatPeer = 0x4d8ddec8,
        InputPeerEmpty = 0x7f3b18ea,
        InputPeerSelf = 0x7da07ec9,
        InputPeerContact = 0x1023dbe8,
        InputPeerForeign = 0x9b447325,
        InputPeerChat = 0x179be863,
        InputPeerNotifyEventsEmpty = 0xf03064d8,
        InputPeerNotifyEventsAll = 0xe86a2c74,
        InputPeerNotifySettings = 0x46a2ce98,
        InputPhotoEmpty = 0x1cd7bf0d,
        InputPhoto = 0xfb95c6c4,
        InputPhotoCropAuto = 0xade6b004,
        InputPhotoCrop = 0xd9915325,
        InputPrivacyKeyStatusTimestamp = 0x4f96cb18,
        InputPrivacyValueAllowContacts = 0x0d09e07b,
        InputPrivacyValueAllowAll = 0x184b35ce,
        InputPrivacyValueAllowUsers = 0x131cc67f,
        InputPrivacyValueDisallowContacts = 0x0ba52007,
        InputPrivacyValueDisallowAll = 0xd66b66c9,
        InputPrivacyValueDisallowUsers = 0x90110467,
        InputStickerSetEmpty = 0xffb62b95,
        InputStickerSetID = 0x9de7a269,
        InputStickerSetShortName = 0x861cc8a0,
        InputUserEmpty = 0xb98886cf,
        InputUserSelf = 0xf7c1b13f,
        InputUserContact = 0x86e94f65,
        InputUserForeign = 0x655e74ff,
        InputVideoEmpty = 0x5508ec75,
        InputVideo = 0xee579652,
        MessageEmpty = 0x83e5de54,
        Message = 0xa7ab1991,
        MessageService = 0x1d86f70e,
        MessageActionEmpty = 0xb6aef7b0,
        MessageActionChatCreate = 0xa6638b9a,
        MessageActionChatEditTitle = 0xb5a1ce5a,
        MessageActionChatEditPhoto = 0x7fcb13a8,
        MessageActionChatDeletePhoto = 0x95e3fbef,
        MessageActionChatAddUser = 0x5e3cfc4b,
        MessageActionChatDeleteUser = 0xb2ae9b0c,
        MessageActionGeoChatCreate = 0x6f038ebc,
        MessageActionGeoChatCheckin = 0x0c7d53de,
        MessageActionChatJoinedByLink = 0xf89cf5e8,
        MessageMediaEmpty = 0x3ded6320,
        MessageMediaPhoto = 0x3d8ce53d,
        MessageMediaVideo = 0x5bcf1675,
        MessageMediaGeo = 0x56e0d474,
        MessageMediaContact = 0x5e7d2f39,
        MessageMediaUnsupported = 0x9f84f49e,
        MessageMediaDocument = 0x2fda2204,
        MessageMediaAudio = 0xc6b68300,
        MessageMediaWebPage = 0xa32dd600,
        MessageMediaVenue = 0x7912b71f,
        MessagesAffectedHistory = 0xb45c69d1,
        MessagesAffectedMessages = 0x84d19185,
        MessagesAllStickersNotModified = 0xe86602c3,
        MessagesAllStickers = 0x5ce352ec,
        MessagesChatFull = 0xe5d7d19c,
        MessagesChats = 0x64ff9fd5,
        MessagesDhConfigNotModified = 0xc0e24635,
        MessagesDhConfig = 0x2c221edd,
        MessagesDialogs = 0x15ba6c40,
        MessagesDialogsSlice = 0x71e094f3,
        InputMessagesFilterEmpty = 0x57e2f66c,
        InputMessagesFilterPhotos = 0x9609a51c,
        InputMessagesFilterVideo = 0x9fc00e65,
        InputMessagesFilterPhotoVideo = 0x56e9f0e4,
        InputMessagesFilterPhotoVideoDocuments = 0xd95e73bb,
        InputMessagesFilterDocument = 0x9eddf188,
        InputMessagesFilterAudio = 0xcfc87522,
        MessagesMessageEmpty = 0x3f4e0648,
        MessagesMessages = 0x8c718e87,
        MessagesMessagesSlice = 0x0b446ae3,
        MessagesSentEncryptedMessage = 0x560f8935,
        MessagesSentEncryptedFile = 0x9493ff32,
        MessagesSentMessage = 0x4c3d47f3,
        MessagesSentMessageLink = 0x35a1a663,
        MessagesStickerSet = 0xb60a24a6,
        MessagesStickersNotModified = 0xf1749a22,
        MessagesStickers = 0x8a8ecd32,
        NearestDc = 0x8e1a1775,
        NotifyPeer = 0x9fd40bd8,
        NotifyUsers = 0xb4c83b4c,
        NotifyChats = 0xc007cec3,
        NotifyAll = 0x74d07c60,
        Null = 0x56730bcc,
        PeerUser = 0x9db1bc6d,
        PeerChat = 0xbad0e5bb,
        PeerNotifyEventsEmpty = 0xadd53cb3,
        PeerNotifyEventsAll = 0x6d1ded88,
        PeerNotifySettingsEmpty = 0x70a68512,
        PeerNotifySettings = 0x8d5e11ee,
        PhotoEmpty = 0x2331b22d,
        Photo = 0xc3838076,
        PhotoSizeEmpty = 0x0e17e23c,
        PhotoSize = 0x77bfb61b,
        PhotoCachedSize = 0xe9a734fa,
        PhotosPhoto = 0x20212ca8,
        PhotosPhotos = 0x8dca6aa5,
        PhotosPhotosSlice = 0x15051f54,
        PrivacyKeyStatusTimestamp = 0xbc2eab30,
        PrivacyValueAllowContacts = 0xfffe1bac,
        PrivacyValueAllowAll = 0x65427b82,
        PrivacyValueAllowUsers = 0x4d5bbe0c,
        PrivacyValueDisallowContacts = 0xf888fa1a,
        PrivacyValueDisallowAll = 0x8b73e763,
        PrivacyValueDisallowUsers = 0x0c7f49b7,
        ReceivedNotifyMessage = 0xa384b779,
        SendMessageTypingAction = 0x16bf744e,
        SendMessageCancelAction = 0xfd5ec8f5,
        SendMessageRecordVideoAction = 0xa187d66f,
        SendMessageUploadVideoAction = 0xe9763aec,
        SendMessageRecordAudioAction = 0xd52f73f7,
        SendMessageUploadAudioAction = 0xf351d7ab,
        SendMessageUploadPhotoAction = 0xd1d34a26,
        SendMessageUploadDocumentAction = 0xaa0cd9e4,
        SendMessageGeoLocationAction = 0x176f8ba1,
        SendMessageChooseContactAction = 0x628cbc6f,
        StickerPack = 0x12b299d4,
        StickerSet = 0xa7a43b17,
        StorageFileUnknown = 0xaa963b05,
        StorageFileJpeg = 0x007efe0e,
        StorageFileGif = 0xcae1aadf,
        StorageFilePng = 0x0a4f63c0,
        StorageFilePdf = 0xae1e508d,
        StorageFileMp3 = 0x528a0677,
        StorageFileMov = 0x4b09ebbc,
        StorageFilePartial = 0x40bc6f52,
        StorageFileMp4 = 0xb3cea0e4,
        StorageFileWebp = 0x1081464c,
        UpdateNewMessage = 0x1f2b0afd,
        UpdateMessageID = 0x4e90bfd6,
        UpdateDeleteMessages = 0xa20db0e5,
        UpdateUserTyping = 0x5c486927,
        UpdateChatUserTyping = 0x9a65ea1f,
        UpdateChatParticipants = 0x07761198,
        UpdateUserStatus = 0x1bfbd823,
        UpdateUserName = 0xa7332b73,
        UpdateUserPhoto = 0x95313b0c,
        UpdateContactRegistered = 0x2575bbb9,
        UpdateContactLink = 0x9d2e67c5,
        UpdateNewAuthorization = 0x8f06529a,
        UpdateNewGeoChatMessage = 0x5a68e3f7,
        UpdateNewEncryptedMessage = 0x12bcbd9a,
        UpdateEncryptedChatTyping = 0x1710f156,
        UpdateEncryption = 0xb4a2e88d,
        UpdateEncryptedMessagesRead = 0x38fe25b7,
        UpdateChatParticipantAdd = 0x3a0eeb22,
        UpdateChatParticipantDelete = 0x6e5f8c22,
        UpdateDcOptions = 0x8e5e9873,
        UpdateUserBlocked = 0x80ece81a,
        UpdateNotifySettings = 0xbec268ef,
        UpdateServiceNotification = 0x382dd3e4,
        UpdatePrivacy = 0xee3b272a,
        UpdateUserPhone = 0x12b9417b,
        UpdateReadHistoryInbox = 0x9961fd5c,
        UpdateReadHistoryOutbox = 0x2f2f21bf,
        UpdateWebPage = 0x2cc36971,
        UpdateReadMessagesContents = 0x68c13933,
        UpdatesTooLong = 0xe317af7e,
        UpdateShortMessage = 0xed5c2127,
        UpdateShortChatMessage = 0x52238b3c,
        UpdateShort = 0x78d4dec1,
        UpdatesCombined = 0x725b04c3,
        Updates = 0x74ae4240,
        UpdatesDifferenceEmpty = 0x5d75a138,
        UpdatesDifference = 0x00f49ca0,
        UpdatesDifferenceSlice = 0xa8fb1981,
        UpdatesState = 0xa56c2a3e,
        UploadFile = 0x096a18d5,
        UserEmpty = 0x200250ba,
        UserSelf = 0x1c60e608,
        UserContact = 0xcab35e18,
        UserRequest = 0xd9ccc4ef,
        UserForeign = 0x075cf7a8,
        UserDeleted = 0xd6016d7a,
        UserFull = 0x771095da,
        UserProfilePhotoEmpty = 0x4f11bae1,
        UserProfilePhoto = 0xd559d8c8,
        UserStatusEmpty = 0x09d05049,
        UserStatusOnline = 0xedb93949,
        UserStatusOffline = 0x008c703f,
        UserStatusRecently = 0xe26f42f1,
        UserStatusLastWeek = 0x07bf09fc,
        UserStatusLastMonth = 0x77ebc742,
        Vector = 0x1cb5c415,
        VideoEmpty = 0xc10658a8,
        Video = 0xee9f4a4d,
        WallPaper = 0xccb03657,
        WallPaperSolid = 0x63117f24,
        WebPageEmpty = 0xeb1477e8,
        WebPagePending = 0xc586da1c,
        WebPage = 0xa31ea0b5,
        BoolFalse = 0xbc799737,
        BoolTrue = 0x997275b5,
        // Methods
        AccountChangePhone = 0x70c32edb,
        AccountCheckUsername = 0x2714d86c,
        AccountDeleteAccount = 0x418d4e0b,
        AccountGetAccountTTL = 0x08fc711d,
        AccountGetAuthorizations = 0xe320c158,
        AccountGetNotifySettings = 0x12b3ad31,
        AccountGetPassword = 0x548a30f5,
        AccountGetPasswordSettings = 0xbc8d11bb,
        AccountGetPrivacy = 0xdadbc950,
        AccountGetWallPapers = 0xc04cfac2,
        AccountRegisterDevice = 0x446c712c,
        AccountResetAuthorization = 0xdf77f3bc,
        AccountResetNotifySettings = 0xdb7e1747,
        AccountSendChangePhoneCode = 0xa407a8f4,
        AccountSetAccountTTL = 0x2442485e,
        AccountSetPrivacy = 0xc9f81ce8,
        AccountUnregisterDevice = 0x65c55b40,
        AccountUpdateDeviceLocked = 0x38df3532,
        AccountUpdateNotifySettings = 0x84be5b93,
        AccountUpdatePasswordSettings = 0xfa7c4b86,
        AccountUpdateProfile = 0xf0888d68,
        AccountUpdateStatus = 0x6628562c,
        AccountUpdateUsername = 0x3e0bdd7c,
        AuthBindTempAuthKey = 0xcdd42a05,
        AuthCheckPassword = 0x0a63011e,
        AuthCheckPhone = 0x6fe51dfb,
        AuthExportAuthorization = 0xe5bfffcd,
        AuthImportAuthorization = 0xe3ef9613,
        AuthLogOut = 0x5717da40,
        AuthRecoverPassword = 0x4ea56e92,
        AuthRequestPasswordRecovery = 0xd897bc66,
        AuthResetAuthorizations = 0x9fab0d1a,
        AuthSendCall = 0x03c51564,
        AuthSendCode = 0x768d5f4d,
        AuthSendInvites = 0x771c1d97,
        AuthSendSms = 0x0da9f3e8,
        AuthSignIn = 0xbcd51581,
        AuthSignUp = 0x1b067634,
        ContactsBlock = 0x332b49fc,
        ContactsDeleteContact = 0x8e953744,
        ContactsDeleteContacts = 0x59ab389e,
        ContactsExportCard = 0x84e53737,
        ContactsGetBlocked = 0xf57c350f,
        ContactsGetContacts = 0x22c6aa08,
        ContactsGetStatuses = 0xc4a353ee,
        ContactsGetSuggested = 0xcd773428,
        ContactsImportCard = 0x4fe196fe,
        ContactsImportContacts = 0xda30b32d,
        ContactsResolveUsername = 0x0bf0131c,
        ContactsSearch = 0x11f812d8,
        ContactsUnblock = 0xe54100bd,
        GeochatsCheckin = 0x55b3e8fb,
        GeochatsCreateGeoChat = 0x0e092e16,
        GeochatsEditChatPhoto = 0x35d81a95,
        GeochatsEditChatTitle = 0x4c8e2273,
        GeochatsGetFullChat = 0x6722dd6f,
        GeochatsGetHistory = 0xb53f7a68,
        GeochatsGetLocated = 0x7f192d8f,
        GeochatsGetRecents = 0xe1427e6f,
        GeochatsSearch = 0xcfcdc44d,
        GeochatsSendMedia = 0xb8f0deff,
        GeochatsSendMessage = 0x061b0044,
        GeochatsSetTyping = 0x08b8a729,
        HelpGetAppUpdate = 0xc812ac7e,
        HelpGetConfig = 0xc4f9186b,
        HelpGetInviteText = 0xa4a95186,
        HelpGetNearestDc = 0x1fb33026,
        HelpGetSupport = 0x9cdf08cd,
        HelpSaveAppLog = 0x6f02f748,
        InitConnection = 0x69796de9,
        InvokeAfterMsg = 0xcb9f372d,
        InvokeAfterMsgs = 0x3dc4b4f0,
        InvokeWithLayer = 0xda9b0d0d,
        InvokeWithoutUpdates = 0xbf9459b7,
        MessagesAcceptEncryption = 0x3dbc0415,
        MessagesAddChatUser = 0xf9a0aa09,
        MessagesCheckChatInvite = 0x3eadb1bb,
        MessagesCreateChat = 0x09cb126e,
        MessagesDeleteChatUser = 0xe0611f16,
        MessagesDeleteHistory = 0xf4f8fb61,
        MessagesDeleteMessages = 0xa5f18925,
        MessagesDiscardEncryption = 0xedd923c5,
        MessagesEditChatPhoto = 0xca4c79d8,
        MessagesEditChatTitle = 0xdc452855,
        MessagesExportChatInvite = 0x7d885289,
        MessagesForwardMessage = 0x33963bf9,
        MessagesForwardMessages = 0x55e1728d,
        MessagesGetAllStickers = 0xaa3bc868,
        MessagesGetChats = 0x3c6aa187,
        MessagesGetDhConfig = 0x26cf8950,
        MessagesGetDialogs = 0xeccf1df6,
        MessagesGetFullChat = 0x3b831c66,
        MessagesGetHistory = 0x92a1df2f,
        MessagesGetMessages = 0x4222fa74,
        MessagesGetStickerSet = 0x2619a90e,
        MessagesGetStickers = 0xae22e045,
        MessagesGetWebPagePreview = 0x25223e24,
        MessagesImportChatInvite = 0x6c50051c,
        MessagesInstallStickerSet = 0xefbbfae9,
        MessagesReadEncryptedHistory = 0x7f4b690a,
        MessagesReadHistory = 0xb04f2510,
        MessagesReadMessageContents = 0x36a73f77,
        MessagesReceivedMessages = 0x05a954c0,
        MessagesReceivedQueue = 0x55a5bb66,
        MessagesRequestEncryption = 0xf64daf43,
        MessagesSearch = 0x07e9f2ab,
        MessagesSendBroadcast = 0xbf73f4da,
        MessagesSendEncrypted = 0xa9776773,
        MessagesSendEncryptedFile = 0x9a901b66,
        MessagesSendEncryptedService = 0x32d439a4,
        MessagesSendMedia = 0x2d7923b1,
        MessagesSendMessage = 0x9add8f26,
        MessagesSetEncryptedTyping = 0x791451ed,
        MessagesSetTyping = 0xa3825e50,
        MessagesUninstallStickerSet = 0xf96e55de,
        PhotosDeletePhotos = 0x87cf7f2f,
        PhotosGetUserPhotos = 0xb7ee553c,
        PhotosUpdateProfilePhoto = 0xeef579a0,
        PhotosUploadProfilePhoto = 0xd50f9c88,
        UpdatesGetDifference = 0x0a041495,
        UpdatesGetState = 0xedd4882a,
        UploadGetFile = 0xe3a6cfb5,
        UploadSaveBigFilePart = 0xde7b673d,
        UploadSaveFilePart = 0xb304a621,
        UsersGetFullUser = 0xca30a5b1,
        UsersGetUsers = 0x0d91a548,
        // End of generated TLValues
    };

    explicit TLValue(quint32 i = 0) :
        m_value(Value(i))
    {
    }

    operator quint32() const
    {
        return m_value;
    }

    bool isValid() const;

    TLValue &operator=(TLValue::Value v)
    {
        m_value = v;
        return *this;
    }

    QString toString() const;
#ifdef DEVELOPER_BUILD
    static TLValue firstFromArray(const QByteArray &data);
#endif

private:
    Value m_value;

};

#endif // TLVALUES_HPP
