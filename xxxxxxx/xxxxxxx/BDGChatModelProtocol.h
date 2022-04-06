//
//  BDGChatModelProtocol.h
//
//  Created by 翁国川 on 2021/1/18.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, BDGChatModelPriority) {
    BDGChatModelPriorityForceShowEnter, //进场，优先级高，必现
    BDGChatModelPriorityForceShow     , // 必现
    BDGChatModelPriorityHigh          ,
    BDGChatModelPriorityMedium        ,
    BDGChatModelPriorityLow
};

@protocol BDGChatModelProtocol <NSObject>
@required
+ (Class)bdg_cellClass;
@optional

// 获取可能采用的富文本
- (NSAttributedString *)attributedString;

// 获取可能的纯文本信息
- (NSString *)content;

// 自行计算内容高度，用于后台计算
- (CGRect)bdg_getFitRectWithWidth:(NSNumber *)width;

// 自行计算内容frame，用于后台计算
- (CGRect)bdg_getFitRectWithHeight:(NSNumber *)height;

// 消息优先级，默认为高
- (BDGChatModelPriority)showPriority;

//该消息是否支持合并逻辑
- (BOOL)isMergedMsg;
- (NSUInteger)mergedTansitionType; //合并类型
- (CGFloat)mergedDuration;

//消息支持边缘设置 UIEdgeInsets CGFloat top, left, bottom, right
- (UIEdgeInsets)messageMarginSpace;




@property (nonatomic, strong) NSDictionary *extDict; //扩展字段

/// 是否在当前频道内的消息（NO 表示其他直播间透传到本直播间的消息）
- (BOOL)isInCurrentChannel;

- (void)setChatWidth:(CGFloat)chatWidth;


@end
