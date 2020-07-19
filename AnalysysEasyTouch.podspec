Pod::Spec.new do |spec|

  spec.name         = "AnalysysEasyTouch"
  spec.version      = "1.1.5.1"
  spec.summary      = "方舟易达 SDK"
  spec.description  = "⾃动化运营平台，通过EA产品帮助客户建⽴起与用户互动的各种桥梁，实现自动化、个性化的触达⽤户，进⽽促进用户增长。"
  spec.homepage     = "https://github.com/AnalysysSDK/AnalysysEasyTouch_iOS"
  spec.license      = { :type => "MIT", :file => "README.md" }
  spec.author       = { "analysys" => "analysys@analysys.com.cn" }
  spec.platform     = :ios, "8.0"
  spec.source       = { :git => "https://github.com/AnalysysSDK/AnalysysEasyTouch_iOS.git", :tag => spec.version }
  spec.vendored_frameworks = "AnalysysEasyTouch.framework"
  spec.requires_arc = true

end
