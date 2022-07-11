#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AnalysysEaConfig.h"
#import "AnalysysBannerConfig.h"
#import "EALogger.h"

NS_ASSUME_NONNULL_BEGIN

@interface AnalysysEaManager : NSObject

#pragma mark - 基础功能

/// 获取事件监听对象，用于实时捕获系统和用户事件
/// @param groupIdentifier App Groups Id
+ (id)getObserverListener:(NSString *)groupIdentifier;

/// 启动SDK
/// @param config 配置信息
+ (void)startWithConfig:(AnalysysEaConfig *)config;

/// 获取 SDK 版本号
+ (NSString *)SDKVersion;

/// 配置日志开关
+ (void)configLogLevel:(EALoggerLevel)logLevel;

#pragma mark - 推送

/// 注册远程推送获取的 deviceToken
/// @param deviceToken APNS 远程推送由系统返回的 NSData 类型的 deviceToken
/// @param groupIdentifier App Groups Id
+ (void)pushToken:(NSData *_Nullable)deviceToken groupIdentifier:(NSString *)groupIdentifier __attribute__((deprecated("已过时！建议使用 pushToken:provider:groupIdentifier: 接口")));

/// 上报唯一设备标识
/// @param deviceId 设备唯一标识 ID（若是 APNS 通道，值为系统直接返回的 deviceToken，若是三方推送通道，比如极光推送，则值为获取的 registrationID）
/// @param provider 推送通道
/// @param groupIdentifier App Groups Id
+ (void)pushToken:(id _Nullable)deviceId provider:(PushProvider)provider groupIdentifier:(NSString *)groupIdentifier;

/// 追踪推送消息
/// @param type 推送消息事件类型，到达/点击
/// @param msg 推送消息
/// @param groupIdentifier App Groups Id
+ (void)pushTrack:(PushEventType)type msg:(NSDictionary *)msg groupIdentifier:(NSString *)groupIdentifier;

#pragma mark - 别名

/// 开启/关闭设置页面别名
/// @param state 为 YES 时开启页面别名设置功能，为 NO 关闭页面别名设置功能
+ (void)setPageTagState:(BOOL)state;

#pragma mark - banner

/// 渲染 banner
/// @param bannerConfig 横幅配置，AnalysysBannerConfig 类对象实例
+ (CGSize)loadBanner:(AnalysysBannerConfig *)bannerConfig;

/// 根据指定的 locationId 获取对应的服务端下发的 banner 活动信息 json，异步返回
/// @param locationIds 指定的 locationId 数组
/// @param completion 接口回调
+ (void)getBanner:(NSArray<NSString *> *)locationIds completion:(void (^)(NSString * _Nullable json))completion;


/// 开启/关闭设置弹窗
/// @param visible 为 YES 时弹窗设置功能，为 NO 关闭弹窗设置功能
+ (void)setDialogVisible:(BOOL)visible;

///上传公众号的ID
+ (void)setWeChatId:(NSString *)unionId appId:(NSString *)appid openId:(NSString *)openId;

///判断当前是否有要处理的弹窗
+ (BOOL )showPopWindow;

@end

NS_ASSUME_NONNULL_END
