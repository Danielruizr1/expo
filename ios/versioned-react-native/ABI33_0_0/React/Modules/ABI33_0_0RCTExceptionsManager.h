/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#import <ReactABI33_0_0/ABI33_0_0RCTBridgeModule.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ABI33_0_0RCTExceptionsManagerDelegate <NSObject>

- (void)handleSoftJSExceptionWithMessage:(nullable NSString *)message stack:(nullable NSArray *)stack exceptionId:(NSNumber *)exceptionId;
- (void)handleFatalJSExceptionWithMessage:(nullable NSString *)message stack:(nullable NSArray *)stack exceptionId:(NSNumber *)exceptionId;

@optional
- (void)updateJSExceptionWithMessage:(nullable NSString *)message stack:(nullable NSArray *)stack exceptionId:(NSNumber *)exceptionId;

@end

@interface ABI33_0_0RCTExceptionsManager : NSObject <ABI33_0_0RCTBridgeModule>

- (instancetype)initWithDelegate:(id<ABI33_0_0RCTExceptionsManagerDelegate>)delegate;

- (void)reportSoftException:(nullable NSString *)message stack:(nullable NSArray<NSDictionary *> *)stack exceptionId:(NSNumber *)exceptionId;
- (void)reportFatalException:(nullable NSString *)message stack:(nullable NSArray<NSDictionary *> *)stack exceptionId:(NSNumber *)exceptionId;

@property (nonatomic, weak) id<ABI33_0_0RCTExceptionsManagerDelegate> delegate;

@property (nonatomic, assign) NSUInteger maxReloadAttempts;

@end

NS_ASSUME_NONNULL_END