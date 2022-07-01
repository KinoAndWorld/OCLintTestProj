//
//  Debug2.h
//  xxxxxxx
//
//  Created by 陈文杰 on 2022/1/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define YY_DIRECT_PROPERTY direct,
#define YY_DIRECT_METHOD __attribute__((objc_direct))

NS_ASSUME_NONNULL_BEGIN

@protocol IYYUInputModuleBridge;

@interface Debug2 : NSObject

@property (nonatomic, assign) int placeInt;

@property (nonatomic, copy) NSString *placeString;
//+ (instancetype)shared;

//+ (void)completeAll YY_DIRECT_METHOD;

@end

@interface Debug2 (UISubclassingGet)

// 分类这样声明 会报错 放在主类不会
//@property (YY_DIRECT_PROPERTY nonatomic, assign, readonly) int currentScrollingListView;

@end


@interface YYUInputModuleBridge : NSObject <IYYUInputModuleBridge>

//- (void)appendToTextViewWithDesc:(NSString *)desc;

@end


@interface YYUInputModuleView : NSObject<IYYUInputModuleBridge>
/**
 *  增加表情描述desc到TextView中
 *
 *  @param desc 要显示在输入框中的表情描述
 */
- (void)appendToTextViewWithDesc:(NSString *)desc;

@end


typedef void(^YYKVOCallBack)(id newValue);
typedef void(^YYKVOMutableCallBack)(NSDictionary<NSString *, NSObject *> *newValues);


@interface YYKVOInfo : NSObject

@property (nonatomic, readonly) NSObject *oldValue;
@property (nonatomic, copy) NSString *keyPath;

/**
 @abstract 移除 info 的观察.
 @discussion 默认会自动释放，用于想提前结束观察的时候.
 */
- (void)unobserve;

/**
 @abstract 设置释放的委托对象
 @discussion 通过这个方法可以将 释放时机 委托给其他对象，在这个对象释放的时候释放.
 */
- (void)disposeBy:(NSObject *)object;

@end

@interface YYKVOController : NSObject

// 单属性KVO，推荐使用宏，有属性提示不用 hardcode.
#define YYObserve(_obj, _path, _block) [YYKVOController observe:_obj keyPath:HW_KEYPATH(_obj, _path) disposeBy:nil block:_block]

/**
 @abstract 观察 object 的 keyPath 属性.
 @param block 返回 object 新的值.
 @param disposer 释放时机的委托对象，nil 表示跟随 object 生命周期释放.
 @discussion 相关对象默认会在 object 释放的时候统一释放，不用额外关注释放.
 */
+ (YYKVOInfo *)observe:(NSObject *)object keyPath:(NSString *)keyPath disposeBy:(NSObject *)disposer block:(YYKVOCallBack)block;

/**
 @abstract 观察 object 的 keyPaths 属性.
 @param block 任一 keypath 发生变化时，都会把所有 keypath 的值回调。若值为 nil，会转换成 NSNull.
        返回所有 keypath 的新值 [{keypath : newValue}]
 @param disposer 释放时机的委托对象，nil 表示跟随 object 生命周期释放.
 @discussion 相关对象默认会在 object 释放的时候统一释放，不用额外关注释放.
 */
+ (NSArray<YYKVOInfo *> *)observe:(NSObject *)object keyPaths:(NSArray<NSString *> *)keyPaths disposeBy:(NSObject *)disposer merge:(YYKVOMutableCallBack)block;

+ (YYKVOInfo *)observe:(NSObject *)object keyPath:(NSString *)keyPath disposeBy:(NSObject *)disposer distinctUntilChanged:(YYKVOCallBack)block;


@end


NS_ASSUME_NONNULL_END
