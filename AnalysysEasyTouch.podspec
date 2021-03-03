Pod::Spec.new do |s|

  s.name         = "AnalysysEasyTouch"
  s.version      = "2.0"
  s.summary      = "方舟智能运营 SDK"
  s.description  = "⾃动化运营平台，通过 EA 产品帮助客户建⽴起与用户互动的各种桥梁，实现自动化、个性化的触达⽤户，进⽽促进用户增长。"
  s.homepage     = "https://github.com/AnalysysSDK/AnalysysEasyTouch_iOS"
  s.license      = { :type => "MIT", :file => "README.md" }
  s.author       = { "analysys" => "analysys@analysys.com.cn" }
  s.platform     = :ios, "9.0"
  s.source       = { :git => "https://github.com/AnalysysSDK/AnalysysEasyTouch_iOS.git", :tag => s.version }
  s.requires_arc = true
  s.xcconfig     = { "EXCLUDED_ARCHS[sdk=iphonesimulator*]" => "arm64"}
  
  # 全量模块
  s.subspec 'AnalysysEasyTouch' do |ss|
    ss.vendored_frameworks = 'AnalysysEasyTouch/Frameworks/AnalysysEasyTouch.framework'
    ss.resource = 'AnalysysEasyTouch/Resources/AnalysysEasyTouch.bundle'
  end
      
  # 通用模块
  s.subspec 'Core' do |ss|
    ss.vendored_frameworks = 'AnalysysEasyTouch/Frameworks/AnalysysEaCore.framework'
  end
  
  # push 模块
  s.subspec 'Push' do |ss|
    ss.vendored_frameworks = 'AnalysysEasyTouch/Frameworks/AnalysysEaPush.framework'
    ss.dependency 'Core'
  end
  
  # 弹窗模块
  s.subspec 'PopWindow' do |ss|
    ss.vendored_frameworks = 'AnalysysEasyTouch/Frameworks/AnalysysEaPopWindow.framework'
    ss.dependency 'Core'
  end
  
  # banner 信息流模块
  s.subspec 'Banner' do |ss|
    ss.vendored_frameworks = 'AnalysysEasyTouch/Frameworks/AnalysysEaBanner.framework'
    ss.dependency 'Core'
  end
  
  # Tag 模块
  s.subspec 'Tag' do |ss|
    ss.vendored_frameworks = 'AnalysysEasyTouch/Frameworks/AnalysysEaTag.framework'
    ss.dependency 'Core'
  end
  
  # RN 支持模块
  s.subspec 'RN' do |ss|
    ss.vendored_frameworks = 'AnalysysEasyTouch/Frameworks/AnalysysEaRNModule.framework'
    ss.dependency 'React'
  end
  
  s.default_subspec = 'AnalysysEasyTouch'

end
