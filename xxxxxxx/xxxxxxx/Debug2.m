//
//  Debug2.m
//  xxxxxxx
//
//  Created by 陈文杰 on 2022/1/24.
//

#import "Debug2.h"
#import "IYYUInputModuleBridge.h"

@interface Debug2()

@property (YY_DIRECT_PROPERTY nonatomic, assign) int currentScrollingListView;

@end

@implementation Debug2

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

- (YYUInputModuleBridge *)anchorService
{
    return [YYUInputModuleBridge new];
}

- (void)normalCall {

}

//- (void)aaaaa
//{
//    id obj;
//    [obj directMethod];
//
////    NSObject *objjj;
//
//}

- (void)directMethod {

}

@end

@implementation YYUInputModuleBridge

#pragma mark - @protocol IInputModuleBridge

- (void)appendToTextViewWithDesc:(NSString *)desc
{
//    [SELF_IMPL.moduleView appendToTextViewWithDesc:desc];
}

@end



@implementation YYUInputModuleView

#pragma mark - 放到IYYUInputModuleBridge去的接口的实现
- (void)appendToTextViewWithDesc:(NSString *)desc
{
//    [self.inputTextView insertText:desc];
}


@end



@implementation YYKVOInfo


@end



@implementation YYKVOController

@end
