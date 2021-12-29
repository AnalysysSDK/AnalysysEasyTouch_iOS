Pod::Spec.new do |s|

  s.name         = "AnalysysEasyTouch"
  s.version      = "2.2.9"
  s.summary      = "方舟易达 SDK"
  s.description  = "⾃动化运营平台，通过EA产品帮助客户建⽴起与用户互动的各种桥梁，实现自动化、个性化的触达⽤户，进⽽促进用户增长。"
  s.homepage     = "https://github.com/AnalysysSDK/AnalysysEasyTouch_iOS"
  s.license      = { :type => "MIT", :file => "README.md" }
  s.author       = { "analysys" => "analysys@analysys.com.cn" }
  s.platform     = :ios, "9.0"
  s.source       = { :git => "https://github.com/AnalysysSDK/AnalysysEasyTouch_iOS.git", :tag => s.version }
  s.vendored_frameworks = "AnalysysEasyTouch.framework"
  s.requires_arc = true
  s.xcconfig     = { "EXCLUDED_ARCHS[sdk=iphonesimulator*]" => "arm64"}

end
