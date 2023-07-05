#import "Debug.h"
//#import "Debug2.h"
#import <objc/runtime.h>

static char const kPropertysCacheKeys;


@implementation KOObserObj


- (void)setMvpHeadTapedBlock:(void (^)(long))mvpHeadTapedBlock
{
    if ([self respondsToSelector:@selector(setMvpHeadTapedBlock:)]) {
        [self setMvpHeadTapedBlock:mvpHeadTapedBlock];
    }

//    BIMSessionManager *sessionManager = [BIMSessionManager ]
}

- (void)playAnimationWithPath:(NSString *)path EffectValue:(NSDictionary *)effectValue
                  A2MFilePath:(NSString *)a2mPath{

    [KOObserObj parseForClass:[KINOSubClass class] withData:nil error:nil];
}

+ (id)parseForClass:(Class)cls withData:(NSData *)data error:(NSError **)error {
    return nil;
}

@end


/* =========================================== */

@implementation InnerClass

@end

@implementation KINOSubClass


+ (instancetype)viewWithTitle:(NSString *)title url:(NSString *)url  {
    KINOSubClass *view = [super viewWithTitle:title];
    return view;
}

- (void)cateFunc1:(id)obj {
//    NSDictionary *dict = [NSDictionary dictionary];
//    KINOSubClass *info = [KINOSubClass yy_modelWithDictionary:dict];
//
//    NSArray *newBanners = [NSArray yy_modelArrayWithClass:[KINOSubClass class] json:nil];
//
//    [NSDictionary yy_modelDictionaryWithClass:KINODebugObject.class json:@{}];
}

- (NSString *)inFather
{
    return @"";
}

+ (instancetype)objectUnmarshallFromData:(NSData *)data
{
    NSError *err = nil;
    id ret = [self yy_parseData:data error:&err hasHead:NO];
    //    if (err) {
    //        LogSelf(@"parse err:%@ for %@",err,self);
    //    }

    // TODO: 支持不了这种
    id ret2 = [[self superclass] yy_parseData:data error:&err hasHead:NO];

    return ret;
}

+ (instancetype)yy_parseData:(NSData *)data error:(NSError * _Nullable __autoreleasing *)error hasHead:(BOOL)hasHead
{
    return [KOObserObj parseForClass:self withData:data error:error];
}

@end

@interface KINODebugObject()

@property (nonatomic, strong, setter=customSetObj:) KOObserObj *myObj;

@property (nonatomic, assign) int sss __attribute((__annotate__(("NODIRECT"))));

@property (nonatomic, copy) NSString *resultSt3; //这是需要检测的变量名

@property (nonatomic, assign) int polProp; //这是需要检测的变量名


@end

@implementation KINODebugObject

- (void)showAnimate  
{

}

- (void)yy_onUserCardShow:(id)userCardView
{
    
}

- (void)funcAA __attribute((__annotate__(("NODIRECT"))))
{
    
}

+ (instancetype)viewWithTitle:(NSString *)title  {
    KINODebugObject *ooo = [KINODebugObject new];
//    ooo.title = title;
    return 000;
}

- (void)customSetObj:(KOObserObj *)obj {
    if ([self.resultSt3 respondsToSelector:@selector(polProp)]) {
        
    }
}

- (KOObserObj *)myObj {
    return [KOObserObj new];
}

- (void)holyFunc  {
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
    NSString *astr = NSStringFromClass([self class]);

    objc_setAssociatedObject([self class], &kPropertysCacheKeys, @[],
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
}

@end


