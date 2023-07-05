//
//  Debug2.m
//  xxxxxxx
//
//  Created by 陈文杰 on 2022/1/24.
//

#import "Debug2.h"
#import "IYYUInputModuleBridge.h"

@interface Debug2()<YYCoreProtocol>

@property (nonatomic, assign) int currentScrollingListView;

@property (nonatomic, assign) int testBB;


@end

@implementation Debug2

//IMPLEMENT_YYCOREPROTOCOL

+ (instancetype)sharedCore
{
    static dispatch_once_t onceToken;
    static id _sharedCore = nil;
    dispatch_once(&onceToken, ^{
        _sharedCore = [[self alloc] init];
    });
    return _sharedCore;
}


- (void)testAAAA
{

}



- (void)pubAAA {
//    [YYKVOController observe:[self endLiveService] keyPath:@"placeInt" disposeBy:self distinctUntilChanged:^(id newValue) {
//
//    }];
//     [YYKVOController observe:[self anchorService] keyPath:@"anchorId" disposeBy:self distinctUntilChanged:^(id newValue) {
//
//     }];

//    NSArray *list = @[@"placeInt", @"placeString"];
//
//    [YYKVOController observe:[self endLiveService] keyPaths:[self funcList] disposeBy:self merge:^(NSDictionary<NSString *,NSObject *> * _Nonnull newValues) {
//
//    }];

    id obj;

    int aa = [obj placeInt];
    id bb = [obj endLiveService];
}

- (Debug2 *)endLiveService
{
    return nil;
}

- (void)directMethod YY_DIRECT_METHOD {
    
}

@end
