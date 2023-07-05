//
//  Debug3.m
//  xxxxxxx
//
//  Created by 陈文杰 on 2023/4/18.
//

#import "Debug3.h"

@implementation Debug3

- (void)testMethod {
    [[[self getSome] superclass] description];

    [[self superclass] description];
}

- (OtherClass *)getSome {
    return [[OtherClass alloc] init];
}

@end


@implementation OtherClass


@end
