//
//  Debug.h
//  xxxxxxx
//
//  Created by 陈文杰 on 2022/1/14.
//

#ifndef Debug_h
#define Debug_h

#import <Foundation/Foundation.h>

#define YYU_DIRECT_PROPERTY direct,
#define YYU_DIRECT_METHOD __attribute__((objc_direct))

//#define YY_PROPERTY_DY_ENABLE 1

#if YY_PROPERTY_DY_ENABLE
#define YYPropertyDynamicClass(ClassName) YYPropertyDynamic##ClassName
#define YYPropertyDynamicProperty(Proterty) @dynamic Proterty;
#else
#define YYPropertyDynamicClass(ClassName) ClassName
#define YYPropertyDynamicProperty(Proterty)
#endif


@protocol KINOProtocol <NSObject>

@property (nonatomic, copy) NSString *protocolProp;

- (void)protocolFunc;

/// id
- (NSString *)identifier;

- (int)polProp;

@end


@interface KOObserObj : NSObject

//@property (nonatomic, assign) NSUInteger count;
@property (nonatomic, copy) void (^mvpHeadTapedBlock)(long uid);

+ (id)parseForClass:(Class)cls withData:(NSData *)data error:(NSError **)error;

@end

@interface KINODebugObject : NSObject<KINOProtocol>

//@property (nonatomic, copy, direct, readonly) NSString *resultSt3; //这是需要检测的变量名
@property (nonatomic, copy) NSString *protocolProp;

@property (nonatomic, copy) NSString *inFather;

+ (instancetype)viewWithTitle:(NSString *)title;

- (void)yy_onUserCardShow:(id)userCardView;

@end

@interface KINODebugObject(NNONNE)<KINOProtocol>

@end

@interface InnerClass : NSObject

@end

@interface KINOSubClass : KINODebugObject

@property (nonatomic, copy) NSString *inFather;

@property (nonatomic, strong) InnerClass *innerrrrr;

@property (nonatomic, strong) NSArray<InnerClass *> *innerList;

@end


#endif /* Debug_h */
