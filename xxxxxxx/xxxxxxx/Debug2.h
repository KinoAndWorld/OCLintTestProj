//
//  Debug2.h
//  xxxxxxx
//
//  Created by 陈文杰 on 2022/1/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Debug.h"

#define YY_DIRECT_PROPERTY direct,
#define YY_DIRECT_METHOD __attribute__((objc_direct))



#define IMPLEMENT_YYCOREPROTOCOL \
+ (instancetype)sharedCore{\
static dispatch_once_t onceToken;\
static id _sharedCore = nil;\
dispatch_once(&onceToken, ^{\
_sharedCore = [[self alloc] init];\
});\
return _sharedCore;\
}\

#define IMPLEMENT_INIT_YYCOREPROTOCOL \
+ (instancetype)shareCoreInit {\
    id sharedCore = [[self alloc] init];\
    return sharedCore;\
}\




#define VOID void
#define BN_Dec(notification,...)       typedef void(^BNBlock_##notification)(__VA_ARGS__);\
                                        @interface NSObject (notification)\
                                        - (void)on##notification:(BNBlock_##notification)callback;\
                                        - (void)on##notification:(BNBlock_##notification)callback queue:(dispatch_queue_t)queue;\
                                        @end\
                                        extern NSString * const notification




NS_ASSUME_NONNULL_BEGIN


@protocol YYCoreProtocol <NSObject>

@required
+ (instancetype)sharedCore;

- (void)testAAAA;

- (void)testBB;

@end



BN_Dec(GuardianCreateRenew_NewNotify, NSObject *info);

typedef void(^BNBlock_GuardianCreateRenew_NewNotify)(NSObject *);
@interface NSObject (GuardianCreateRenew_NewNotify)
  - (void)onGuardianCreateRenew_NewNotify:(BNBlock_GuardianCreateRenew_NewNotify)callback;
  - (void)onGuardianCreateRenew_NewNotify:(BNBlock_GuardianCreateRenew_NewNotify)callback queue:(dispatch_queue_t)queue;
@end

extern NSString * const GuardianCreateRenew_NewNotify;


@interface Debug2 : NSObject

@property (nonatomic, assign) int placeInt;

@property (nonatomic, copy) NSString *placeString;
//+ (instancetype)shared;

//+ (void)completeAll YY_DIRECT_METHOD;

+ (instancetype)sharedCore;

- (void)testAAAA;

@end

@interface Debug2 (UISubclassingGet)

// 分类这样声明 会报错 放在主类不会
//@property (YY_DIRECT_PROPERTY nonatomic, assign, readonly) int currentScrollingListView;

@end


NS_ASSUME_NONNULL_END
