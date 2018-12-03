//
//  YCFormDataConfig.h
//  YCNetWorking
//
//  Created by 安跃超 on 2018/12/1.
//  Copyright © 2018年 安跃超. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
#pragma mark - 用于拼接formData的协议
@protocol YCMultipartFormDataProtocol
- (BOOL)appendPartWithFileURL:(NSURL *)fileURL
                         name:(NSString *)name
                        error:(NSError * __nullable __autoreleasing *)error;
- (BOOL)appendPartWithFileURL:(NSURL *)fileURL
                         name:(NSString *)name
                     fileName:(NSString *)fileName
                     mimeType:(NSString *)mimeType
                        error:(NSError * __nullable __autoreleasing *)error;
- (void)appendPartWithInputStream:(nullable NSInputStream *)inputStream
                             name:(NSString *)name
                         fileName:(NSString *)fileName
                           length:(int64_t)length
                         mimeType:(NSString *)mimeType;
- (void)appendPartWithFileData:(NSData *)data
                          name:(NSString *)name
                      fileName:(NSString *)fileName
                      mimeType:(NSString *)mimeType;
- (void)appendPartWithFormData:(NSData *)data
                          name:(NSString *)name;
- (void)appendPartWithHeaders:(nullable NSDictionary *)headers
                         body:(NSData *)body;
- (void)throttleBandwidthWithPacketSize:(NSUInteger)numberOfBytes
                                  delay:(NSTimeInterval)delay;
@end

@interface YCFormDataConfig : NSObject
// 用于二进制数据的formData拼接
+ (void (^)(id<YCMultipartFormDataProtocol>))configWithData:(NSData *)data
                                                       name:(NSString *)name
                                                   fileName:(NSString *)fileName
                                                   mimeType:(NSString *)mimeType;

// 用于图片数据的formData拼接
+ (void (^)(id<YCMultipartFormDataProtocol>))configWithImage:(UIImage *)image
                                                        name:(NSString *)name
                                                    fileName:(NSString *)fileName
                                                     quality:(CGFloat)quality;

// 用于url所在数据的formData拼接
+ (void (^)(id<YCMultipartFormDataProtocol>))configWithFileURL:(NSURL *)fileURL
                                                          name:(NSString *)name
                                                      fileName:(NSString *)fileName
                                                      mimeType:(NSString *)mimeType
                                                         error:(NSError * __nullable __autoreleasing *)error;

// 用于NSInputStream获取数据的formData拼接
+ (void (^)(id<YCMultipartFormDataProtocol>))configWithInputStream:(nullable NSInputStream *)inputStream
                                                              name:(NSString *)name
                                                          fileName:(NSString *)fileName
                                                            length:(int64_t)length
                                                          mimeType:(NSString *)mimeType;
@end

NS_ASSUME_NONNULL_END
