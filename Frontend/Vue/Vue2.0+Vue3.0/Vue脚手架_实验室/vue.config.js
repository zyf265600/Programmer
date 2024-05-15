const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  transpileDependencies: true,
  lintOnSave:false, //关闭语法检查
  //开启代理服务器
  devServer: {
    proxy: 'http://localhost:5000' //这里写后端服务器位置 
  }

})
