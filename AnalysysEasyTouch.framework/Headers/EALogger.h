#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define EALogLevel(level,fmt,...)                           \
        [EALogger log:level                                 \
        function:__PRETTY_FUNCTION__                        \
        format:(fmt), ## __VA_ARGS__]

#define EA_Debug(fmt, ...) EALogLevel(EALoggerLevelDebug, (fmt), ## __VA_ARGS__)
#define EA_Log(fmt, ...) EALogLevel(EALoggerLevelInfo, (fmt), ## __VA_ARGS__)
#define EA_Warn(fmt, ...) EALogLevel(EALoggerLevelWarn, (fmt), ## __VA_ARGS__)
#define EA_Error(fmt, ...) EALogLevel(EALoggerLevelError, (fmt), ## __VA_ARGS__)
#define EA_Data(fmt, ...) EALogLevel(EALoggerLevelData, (fmt), ## __VA_ARGS__)

/// 日志类型
typedef NS_ENUM(NSInteger, EALoggerLevel) {
    EALoggerLevelDebug,   // 调试日志
    EALoggerLevelVerbose, // 输出全部日志
    EALoggerLevelNone,    // 不输出日志
    EALoggerLevelInfo,
    EALoggerLevelWarn,
    EALoggerLevelError,
    EALoggerLevelData,
};

/// 默认的存储日志的文件夹名称
FOUNDATION_EXPORT NSString *const EADefaultLogDirectoryName;

/// 异步日志记录，将写操作放入串行队列
@interface EALogger : NSObject

/// 配置日志输出类型，需要在日志输出前提前配置，若不配置，默认输出调试日志
/// @param logLevel 日志输出类型
+ (void)configLogLevel:(EALoggerLevel)logLevel;

+ (void)log:(NSInteger)level function:(const char *)function format:(NSString *)format, ...;

@end

NS_ASSUME_NONNULL_END
