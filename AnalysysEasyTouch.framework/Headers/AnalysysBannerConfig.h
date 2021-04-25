#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 横幅配置
@interface AnalysysBannerConfig : NSObject

/// 获取 AnalysysBannerConfig 对象唯一实例
+ (instancetype)defaultConfig;

/// 标识 banner 位置的 ID，必填
@property (nonatomic, copy) NSString *locationId;

/// 装载 banner 的容器，非必填，若调用 AnalysysEaManager loadBanner 接口返回 cell 行高，该值可不必传
@property (nonatomic, weak) UIView *container;

/// 当事件未触发或活动已结束时，将不展示 banner，非必填，默认 NO
@property (nonatomic, assign) BOOL hidesWhenNotAvailable;

@end

NS_ASSUME_NONNULL_END
