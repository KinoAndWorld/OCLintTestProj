//
//  IInputModuleBridge.h
//  YYMobile
//
//  Created by Arcfat Tsui on 12/16/15.
//  Copyright © 2015 YY.inc. All rights reserved.
//

 //YY_NO_DIRECT
#import <Foundation/Foundation.h>
@protocol IYYUEmoticonParser;
@protocol YYUInputTextHandlerProtocol;

@protocol IYYUInputModuleBridge <NSObject>

/**
 *  增加表情描述desc到TextView中
 *
 *  @param desc 要显示在输入框中的表情描述
 */
- (void)appendToTextViewWithDesc:(NSString *)desc;

/**
 *  调用这个方法直接发送消息，不会显示到Textfield中
 *  use case: 比如点击了一个表情直接发送出去，不用显示表情描述在Textfield中的时候，可以调用这个接口
 *
 *  @param msg    要发送的消息
 *  @param length 消息长度
 */
- (void)sendMessage:(NSString *)msg msgLength:(NSNumber *)length;

/**
 *  返回Textfield
 *
 */
- (UITextField *)getInputTextField;

/**
 *  直接设置Textfield字符串
 *
 */
- (void)setTextfieldText:(NSString *)text;

/**
 *  返回Textfield当前字符串
 *
 */
- (NSString *)currentTextInTextfield;

/**
 *  Replace the text in textfield that is in the specified range.
 *
 *  @param range A range of text in a textfield
 *  @param text  A string to replace the text in range
 */
- (void)replaceTextfieldRange:(NSRange)range withText:(NSString *)text;

/**
 *  切换到相应的EmoticonView时的回调(比如本来是默认表情的View，点击了贵族表情icon后切换到贵族表情的View时会触发回调，反之亦然)
 *
 */
- (void)setDidChangeToEmoticonViewBlock:(void (^)(UIView *emoticonView))block;

/**
 *  是否应该打开输入组件(比如用户被禁言了就返回NO表明不用打开输入了)
 *  **注意**不用在这个block里面做登录检查，组件内部会检查的
 *
 *  @param block 如果要设置的block返回YES表示可以show，NO表示不可以show
 */
- (void)setShouldShowInputViewBlock:(BOOL (^)(void))block;

/**
 *  Sets a callback to be executed when the inputView will show.
 *
 *  @param block A block object to be called when the inputView will show. This block has no return value and takes
 * three arguments: the UIViewAnimationCurve of keyboard, the animation interval, and the frame of inputView(include
 * keyboard).
 */
- (void)setInputViewWillShowBlock:(void (^)(UIViewAnimationCurve curve, CGFloat interval, CGRect viewFrame))block;

/**
 *  Sets a callback to be executed when the inputView will hide.
 *
 *  @param block A block object to be called when the inputView will hide. This block has no return value and takes
 * three arguments: the UIViewAnimationCurve of keyboard, the animation interval, and the frame of inputView(include
 * keyboard).
 */
- (void)setInputViewWillHideBlock:(void (^)(UIViewAnimationCurve curve, CGFloat interval, CGRect viewFrame))block;

/**
 *  Sets a callback to be executed when user tap the "send(表情的发送键)" button on emoticonView, or the
 * "return/sent(键盘的发送键)" button on keyboard. You can use this block to configure the text will be sent out.
 *  这里的这个block是在点击了发送的时候回调的，业务方可以在这个block里做一些业务相关的逻辑，block返回值是一个字典，这个字典应该有三个键值对，对应关系如下所示(以key-value形式表示)：
 *  kShouldSend-@(YES/NO) : 表示是否应该发送消息，YES发送，NO不发送
 *  kMsgToSend-NSString   : 在这个block中已经传入了message，如果要修改，则把修改后要发送的放在这个键值对里
 *  kMsgLength-NSNumber   :
 * 表示message的有效长度，在这个block中已经传入了表情转换之后的有效长度，如果修改了message，注意返回相应有效长度
 *
 *  @param block A block object to be called when user tap the "send(表情的发送键)" button on emoticonView, or the
 * "return/sent(键盘的发送键)" button on keyboard. This block returns an NSDictionary and takes two arguments: the
 * message to be sent, and the effective length of meassage.
 */
- (void)setWillSendMessageBlock:(NSDictionary * (^)(NSString *message, NSNumber *msgLength))block;

- (void)setInputViewCanSendMessageBlock:(BOOL (^)(NSString *message))block;

/**
 *  输入框是否为第一响应者
 */
- (BOOL)isInputTextfieldFirstResponder;

- (BOOL)isInPutShow;

// 限制热词长度
- (void)updateHotWordLengthLimit:(NSInteger)count;

@end
