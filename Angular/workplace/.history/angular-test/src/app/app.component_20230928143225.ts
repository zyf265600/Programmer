import { Component } from "@angular/core"

@Component({
  // 指定组件的使用方式, 当前为标记形式
  // app-home   =>  <app-home></app-home>
	// [app-home] =>  <div app-home></div>
  // .app-home  =>  <div class="app-home"></div>
  selector: 'app-root',
  // 关联组件模板文件
  // templateUrl:'组件模板文件路径'
	// template:`组件模板字符串`
  templateUrl: './app.component.html',
  // 关联组件样式文件
  // styleUrls : ['组件样式文件路径']
	// styles : [`组件样式`]
  styleUrls: ["./app.component.css"]
})
export class AppComponent {
  title = 'angular-test';

  <h2>{{message}}</h2>
<h2>{{getInfo()}}</h2>
<h2>{{a == b ? '相等': '不等'}}</h2>
<h2>{{'Hello Angular'}}</h2>
<p [innerHTML]="htmlSnippet"></p> <!-- 对数据中的代码进行转义 -->
}