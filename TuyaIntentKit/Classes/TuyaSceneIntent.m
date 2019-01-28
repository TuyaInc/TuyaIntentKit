//
// TuyaSceneIntent.m
//
// This file was automatically generated and should not be edited.
//

#import "TuyaSceneIntent.h"

@implementation TuyaSceneIntent

@dynamic sceneName, sceneIdKey, iconUrl, userID, currentHomeID;

@end

@interface TuyaSceneIntentResponse ()

@property (readwrite, NS_NONATOMIC_IOSONLY) TuyaSceneIntentResponseCode code;

@end

@implementation TuyaSceneIntentResponse

@synthesize code = _code;

@dynamic sceneName;

- (instancetype)initWithCode:(TuyaSceneIntentResponseCode)code userActivity:(nullable NSUserActivity *)userActivity {
    self = [super init];
    if (self) {
        _code = code;
        self.userActivity = userActivity;
    }
    return self;
}

@end
