#import "Debug.h"
#import "Debug2.h"
#import <objc/runtime.h>

static char const kPropertysCacheKeys;

//
//
@implementation NSString (BDGame)

- (BOOL)hasPrefix:(NSString *)str {
    return NO;
}

+ (NSString *)bdg_bigNumDescWithNumber:(NSUInteger)num {
    if (num == 0) {
        return @"0";
    }

    NSUInteger value = num;
    if (value >= 100000) {
        return [NSString stringWithFormat:@"%0.2f万", value/10000.0];
    }
    NSNumberFormatter *formatter = [[NSNumberFormatter alloc] init];
    formatter.numberStyle = NSNumberFormatterDecimalStyle;
    return [formatter stringFromNumber:@(value)];
}

@end



@implementation KOObserObj

@end



@interface KINODebugObject()

@property (nonatomic, strong, setter=customSetObj:) KOObserObj *myObj;

@property (nonatomic, assign) int sss __attribute((__annotate__(("NODIRECT"))));

@property (nonatomic, copy, direct) NSString *resultSt3; //这是需要检测的变量名

@end

@implementation KINODebugObject

- (void)funcAA __attribute((__annotate__(("NODIRECT"))))
{

}

+ (instancetype)viewWithTitle:(NSString *)title  {
    KINODebugObject *ooo = [KINODebugObject new];
//    ooo.title = title;
    return 000;
}

- (void)customSetObj:(KOObserObj *)obj {

}

- (KOObserObj *)myObj {
    return [KOObserObj new];
}

- (void)holyFunc {
    [self performSelector:NSSelectorFromString(@"canNotDirect")];

    self.myObj = [[KOObserObj alloc] init];
    [self.myObj addObserver:self forKeyPath:@"count" options:NSKeyValueObservingOptionNew context:nil];
}

- (NSString *)identifier
{
    return @"";
}

//!OCLINT
- (void)protocolFunc {
//    KINOSubClass2 *inst = [KINOSubClass2 share];
//    [self performSelector:@selector(showMe)];

    Debug2 *vc = [Debug2 new];

    [vc performSelector:@selector(showMe)];


//    [[KINOSubClass2 class] viewWithTitle:@"xxxxxxxx"];
    NSString *astr = NSStringFromClass([self class]);

    objc_setAssociatedObject([self class], &kPropertysCacheKeys, @[],
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
}

@end

//
//
@interface KINODebugObject(TestADDI)

@property (nonatomic, copy) NSString *categoryName;

- (void)cateFunc1;

- (NSString *)bdg_nickWithUid:(NSString *)uid;

@end

@implementation KINODebugObject(TestADDI)


- (void)cateFunc1:(id)obj __attribute__((objc_direct))
{

}

- (NSString *)bdg_nickWithUid:(NSString *)uid;
{
    return @"";
}

@end


/* =========================================== */



@implementation KINOSubClass


+ (instancetype)viewWithTitle:(NSString *)title url:(NSString *)url {
    KINOSubClass *view = [super viewWithTitle:title];
    return view;
}

@end


/* =========================================== */


@implementation KINOSubClass2

+ (instancetype)share __attribute__((objc_direct))
{
    static KINOSubClass2 *obj = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        obj = [[KINOSubClass2 alloc] init];
    });
    return obj;
}

+ (void)showMe {
//    [[self share] showMe];
}

- (void)showMe {

}

@end




//
//@implementation NSString (BDGame2)
//
//+ (NSString *)bdg_bigNumDescWithNumber:(NSUInteger)num
//{
//    return @"";
//}
//
//@end
