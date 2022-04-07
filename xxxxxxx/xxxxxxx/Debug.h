//
//  Debug.h
//  xxxxxxx
//
//  Created by 陈文杰 on 2022/1/14.
//

#ifndef Debug_h
#define Debug_h

#import <Foundation/Foundation.h>

#define YY_DIRECT_PROPERTY direct,
#define YY_DIRECT_METHOD __attribute__((objc_direct))

@protocol KINOProtocol <NSObject>

@property (nonatomic, copy) NSString *protocolProp;

- (void)protocolFunc;

/// id
- (NSString *)identifier;

- (int)polProp;

@end


@interface KOObserObj : NSObject

//@property (nonatomic, assign) NSUInteger count;

@end

@interface KINODebugObject : NSObject<KINOProtocol>

//@property (nonatomic, copy, direct, readonly) NSString *resultSt3; //这是需要检测的变量名
@property (nonatomic, copy) NSString *protocolProp;

@property (nonatomic, copy) NSString *inFather;

+ (instancetype)viewWithTitle:(NSString *)title;

@end

@interface KINODebugObject (XXXX)

//@property (nonatomic, assign, readonly) int findMe;
//
//@property (direct, strong, nonatomic) NSString *content;

@end

@interface KINOSubClass : KINODebugObject

@property (nonatomic, copy) NSString *inFather;

@end

@interface KINOSubClass2 : KINODebugObject

+ (instancetype)share __attribute__((objc_direct));

+ (void)showMeByClass;

- (void)showMeByInstance;

@end


#endif /* Debug_h */
