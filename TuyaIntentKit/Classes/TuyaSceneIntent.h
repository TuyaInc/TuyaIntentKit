//
// TuyaSceneIntent.h
//
// This file was automatically generated and should not be edited.
//

#import <Intents/Intents.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(12.0), watchos(5.0))
@interface TuyaSceneIntent : INIntent

@property (readwrite, copy, nullable, nonatomic) NSString *sceneName;
@property (readwrite, copy, nullable, nonatomic) NSString *sceneIdKey;
@property (readwrite, copy, nullable, nonatomic) NSString *iconUrl;
@property (readwrite, copy, nullable, nonatomic) NSString *userID;
@property (readwrite, copy, nullable, nonatomic) NSString *currentHomeID;
@property (readwrite, copy, nullable, nonatomic) NSString *sceneId;

@end

@class TuyaSceneIntentResponse;

/*!
 @abstract Protocol to declare support for handling a TuyaSceneIntent. By implementing this protocol, a class can provide logic for resolving, confirming and handling the intent.
 @discussion The minimum requirement for an implementing class is that it should be able to handle the intent. The confirmation method is optional. The handling method is always called last, after confirming the intent.
 */
API_AVAILABLE(ios(12.0), watchos(5.0))
@protocol TuyaSceneIntentHandling <NSObject>

@required

/*!
 @abstract Handling method - Execute the task represented by the TuyaSceneIntent that's passed in
 @discussion Called to actually execute the intent. The app must return a response for this intent.

 @param  intent The input intent
 @param  completion The response handling block takes a TuyaSceneIntentResponse containing the details of the result of having executed the intent

 @see  TuyaSceneIntentResponse
 */
- (void)handleTuyaScene:(TuyaSceneIntent *)intent completion:(void (^)(TuyaSceneIntentResponse *response))completion NS_SWIFT_NAME(handle(intent:completion:));

@optional

/*!
 @abstract Confirmation method - Validate that this intent is ready for the next step (i.e. handling)
 @discussion Called prior to asking the app to handle the intent. The app should return a response object that contains additional information about the intent, which may be relevant for the system to show the user prior to handling. If unimplemented, the system will assume the intent is valid, and will assume there is no additional information relevant to this intent.

 @param  intent The input intent
 @param  completion The response block contains a TuyaSceneIntentResponse containing additional details about the intent that may be relevant for the system to show the user prior to handling.

 @see TuyaSceneIntentResponse
 */
- (void)confirmTuyaScene:(TuyaSceneIntent *)intent completion:(void (^)(TuyaSceneIntentResponse *response))completion NS_SWIFT_NAME(confirm(intent:completion:));

@end

/*!
 @abstract Constants indicating the state of the response.
 */
typedef NS_ENUM(NSInteger, TuyaSceneIntentResponseCode) {
    TuyaSceneIntentResponseCodeUnspecified = 0,
    TuyaSceneIntentResponseCodeReady,
    TuyaSceneIntentResponseCodeContinueInApp,
    TuyaSceneIntentResponseCodeInProgress,
    TuyaSceneIntentResponseCodeSuccess,
    TuyaSceneIntentResponseCodeFailure,
    TuyaSceneIntentResponseCodeFailureRequiringAppLaunch,
    TuyaSceneIntentResponseCodeFailureUnlogin = 100,
    TuyaSceneIntentResponseCodeFailureNotCurrentHome
} API_AVAILABLE(ios(12.0), watchos(5.0));

API_AVAILABLE(ios(12.0), watchos(5.0))
@interface TuyaSceneIntentResponse : INIntentResponse

- (instancetype)init NS_UNAVAILABLE;

/*!
 @abstract Initializes the response object with the specified code and user activity object.
 @discussion The app extension has the option of capturing its private state as an NSUserActivity and returning it as the 'currentActivity'. If the app is launched, an NSUserActivity will be passed in with the private state. The NSUserActivity may also be used to query the app's UI extension (if provided) for a view controller representing the current intent handling state. In the case of app launch, the NSUserActivity will have its activityType set to the name of the intent. This intent object will also be available in the NSUserActivity.interaction property.

 @param  code The response code indicating your success or failure in confirming or handling the intent.
 @param  userActivity The user activity object to use when launching your app. Provide an object if you want to add information that is specific to your app. If you specify nil, the system automatically creates a user activity object for you, sets its type to the class name of the intent being handled, and fills it with an INInteraction object containing the intent and your response.
 */
- (instancetype)initWithCode:(TuyaSceneIntentResponseCode)code userActivity:(nullable NSUserActivity *)userActivity NS_DESIGNATED_INITIALIZER;

@property (readwrite, copy, nullable, nonatomic) NSString *sceneName;

/*!
 @abstract The response code indicating your success or failure in confirming or handling the intent.
 */
@property (readonly, NS_NONATOMIC_IOSONLY) TuyaSceneIntentResponseCode code;

@end

NS_ASSUME_NONNULL_END
