#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// SDK 运行环境
typedef NS_ENUM(NSUInteger, EnvType) {
    ENV_DISTRIBUTION, // 线上环境
    ENV_TEST,         // 测试环境
    ENV_DEV,          // 开发环境
    ENV_DEMO,         // demo 环境
};

/// 日志类型输出
typedef NS_ENUM(NSUInteger, LogLevel) {
    LogLevel_DEBUG,   // 输出 debug 日志
    LogLevel_VERBOSE, // 输出全部可见日志
    LogLevel_NONE,    // 不输出日志
    LogLevel_INFO,    // 输出常规信息 [AnalysysEasyTouch][Log] 标记
    LogLevel_WARN,    // 输出警告信息 [AnalysysEasyTouch][Warn] 标记
    LogLevel_ERROR,   // 输出错误信息 [AnalysysEasyTouch][Error] 标记
    LogLevel_Data,    // 输出所有信息，包含请求与响应数据
};

/// 推送通道
typedef NS_ENUM(NSUInteger, PushProvider) {
    PUSH_PROVIDER_APNS,  // APNS 原生通道
    PUSH_PROVIDER_JPUSH, // 极光推送
    PUSH_PROVIDER_GETUI, // 个推推送
    PUSH_PROVIDER_TPNS, //TPNS推送
};

/// 处理推送消息的类型，推送触达或者点击了推送消息
typedef NS_ENUM(NSUInteger, PushEventType) {
    PUSH_RECEIVE, // 收到推送消息
    PUSH_CLICK    // 点击推送消息
};



extern NSString * const EAAnalysysReadyShowWindow;//活动弹窗即将展示通知
extern NSString * const EAAnalysysShowWindowContentClicked;//弹窗活动内容被点击




@protocol EASDKActiveDelegate <NSObject>

@optional

/// 弹窗即将弹出
- (void)popWindowWillShow;
///banner信息流即将展示
- (void)bannerFlowWillShowWithLocation:(NSString *)locationID;

///banner信息流被点击(仅针对匹配活动的信息流)
- (void)bannerFlowDidClickWithLink:(NSString *)eventLink isH5:(BOOL )isH5 location:(NSString *)locationID;
/// 弹窗图片区域被点击
- (void)popWindowDidClickWithLink:(NSString *)eventLink isH5:(BOOL )isH5;

@end

/// SDK 初始化配置类
@interface AnalysysEaConfig : NSObject

/// 获取 AnalysysEaConfig 对象唯一实例
+ (instancetype)defaultConfig;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// 初始化时传入的 appKey ，由创建项目时自动生成，必填
@property (nonatomic, copy) NSString *appKey;
@property (nonatomic, copy) NSString *ubaAppKey;
/// app 创建的 App Groups ID，必填
@property (nonatomic, copy) NSString *applicationGroupIdentifier;

/// 监听远程推送系统回调方法的代理类，必填
/// 如在 AppDelegate 中调用 startWithConfig: 方法并监听推送回调，则传入 self
@property (nonatomic, strong) id notificationCenterDelegate;

/// SDK 运行环境，默认为线上环境，非必填
@property (nonatomic, assign) EnvType envType;

/// 指定输出日志类型，非必填
@property (nonatomic, assign) LogLevel logLevelType;

/// APP 首页视图控制器名称（XXXController），非必填，设置后，创建的基于启动弹窗将会在该首页展示；
/// 若不设置，创建的基于启动弹窗将可能在 APP 出现的第一个页面上展示（如广告页）
@property (nonatomic, copy) NSString *mainPage;

/// 关闭 EA 注册远程推送，非必填，默认 NO
/// 设置为 YES 后 EA 系统将不会注册远程推送消息，但调用 pushToken 接口依然能正常上报 deviceToken
@property (nonatomic, assign) BOOL pushClosed;

/// 推送通道（APNS，极光），非必填
@property (nonatomic, assign) PushProvider pushProvider;

/// 配置 SDK 请求的 URL，非必填，默认为 EA 的服务器 URL
@property (nonatomic, copy) NSString *url;

/// 关闭 banner 信息流功能，非必填，默认 NO
@property (nonatomic, assign) BOOL bannerClosed;

@property (nonatomic, copy) NSString *uploadUrl;



/// 是否需要自动处理弹窗与信息流的点击事件,默认YES
@property (nonatomic, assign) BOOL autoHandleClick;

@property (nonatomic, weak,nullable) id <EASDKActiveDelegate>notificationWindowDelegate;

@end

NS_ASSUME_NONNULL_END
