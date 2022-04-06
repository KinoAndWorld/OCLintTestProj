//
//  Debug2.m
//  xxxxxxx
//
//  Created by 陈文杰 on 2022/1/24.
//

#import "Debug2.h"

@implementation Debug2

@end



@implementation YYUViewAnimationChainItem

+ (instancetype)animationItemWithDuration:(CGFloat)duration animation:(void (^)(void))animation completion:(void (^)(BOOL finished))completion

{
    return [self animationItemWithDuration:duration before:nil animation:animation completion:completion];
}

+ (instancetype)animationItemWithDuration:(CGFloat)duration before:(void (^)(void))before animation:(void (^)(void))animation completion:(void (^)(BOOL finished))completion

{
    YYUViewAnimationChainItem *item = [YYUViewAnimationChainItem new];
    item.duration = duration;
    item.animationsBlock = animation;
    item.completionBlock = completion;
    item.beforeBlock = before;
    return item;
}

@end


@interface YYUViewAnimationChainor ()

@property (nonatomic, assign) BOOL isAnimation;
@property (nonatomic, strong) NSMutableArray <YYUViewAnimationChainItem *> *chainedItems;

@end

@implementation YYUViewAnimationChainor


- (void)startAnimation
{
    if (self.isAnimation) {
        return;
    }
    self.isAnimation = YES;
    [self animationFirstItem];
}

- (void)stopAnimation
{
    if (!self.isAnimation) {
        return;
    }
    self.isAnimation = NO;
}

- (void)addAnimationItems:(NSArray <YYUViewAnimationChainItem *> *)items

{
    if (self.isAnimation) {
        NSAssert(NO, @"animationing can't add");
        return;
    }

    [self.chainedItems removeAllObjects];
    if (items.count) {
        [self.chainedItems addObjectsFromArray:items];
    }
}

- (void)animationFirstItem

{
    if (!self.isAnimation) {
        return;
    }

    if (!self.chainedItems.count) {
        [self finishWithError:nil];
        return;
    }

    YYUViewAnimationChainItem *first = [self.chainedItems firstObject];
    if (!first.animationsBlock) {
        [self finishWithError:[NSError errorWithDomain:@"chainItem is invalid" code:-1 userInfo:nil]];
        return;
    }

    if (first.waitBeforeA > 0) {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(first.waitBeforeA * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            if (!self) {
                return;
            }
            first.waitBeforeA = 0;
            [self animationFirstItem];
        });
        return;
    }

    if (first.beforeBlock) {
        first.beforeBlock();
    }

    [UIView animateWithDuration:first.duration animations:first.animationsBlock completion:^(BOOL finished) {
        if (!self) {
            return;
        }

        if (first.completionBlock) {
            first.completionBlock(finished);
        }
        [self.chainedItems removeObject:first];
        [self animationFirstItem];
    }];
}


- (void)finishWithError:(NSError *)error
{
    if (self.completionBlock) {
        self.completionBlock(error);
    }
    [self stopAnimation];
}


#pragma mark - getter
- (NSMutableArray <YYUViewAnimationChainItem *> *)chainedItems
{
    if (!_chainedItems) {
        _chainedItems = [NSMutableArray new];
    }
    return _chainedItems;
}

@end
