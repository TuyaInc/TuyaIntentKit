Pod::Spec.new do |s|
  s.name             = 'TuyaIntentKit'
  s.version          = '0.1.0'
  s.summary			 = 'intent kit from Tuya'
  s.homepage         = 'https://www.tuya.com'
  s.author           = { 'TuyaInc' => 'https://www.tuya.com' }
  s.source           = { :git => 'https://github.com/TuyaInc/TuyaIntentKit.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
  
  s.frameworks = 'UIKit', 'Foundation','Intents','IntentsUI'

  s.source_files = 'TuyaIntentKit/Classes/**/*'
  s.resources = ['TuyaIntentKit/Assets/*.{png,xib,plist,xcassets,bundle,intentdefinition}']
  
end
