//
//  Debug2.h
//  xxxxxxx
//
//  Created by 陈文杰 on 2022/1/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface Debug2 : NSObject

- (void)aaaaa;

+ (instancetype)share;

@end


@interface YYUViewAnimationChainItem : NSObject

// 等待多久后才执行动画
@property (nonatomic, assign) CGFloat waitBeforeA;
@property (nonatomic, assign) CGFloat duration;

@property (nonatomic, copy, nullable) void (^beforeBlock)(void);
@property (nonatomic, copy) void (^animationsBlock)(void);
@property (nonatomic, copy, nullable) void (^completionBlock)(BOOL finished);

+ (instancetype)animationItemWithDuration:(CGFloat)duration animation:(void (^)(void))animation completion:(void (^_Nullable)(BOOL finished))completion ;

+ (instancetype)animationItemWithDuration:(CGFloat)duration before:(void (^_Nullable)(void))before animation:(void (^)(void))animation completion:(void (^_Nullable)(BOOL finished))completion ;


@end


@interface YYUViewAnimationChainor : NSObject

@property (nonatomic, assign, readonly) BOOL isAnimation;
@property (nonatomic, copy) void (^completionBlock)(NSError *error);

- (void)startAnimation ;
- (void)stopAnimation ;
- (void)addAnimationItems:(NSArray <YYUViewAnimationChainItem *> *)items ;

@end

NS_ASSUME_NONNULL_END
