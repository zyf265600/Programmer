// BrowserModule 提供了启动和运行浏览器应用所必需的服务
// CommonModule 提供各种服务和指令, 例如 ngIf 和 ngFor, 与平台无关
// BrowserModule 导入了 CommonModule, 又重新导出了 CommonModule, 使其所有指令都可用于导入 BrowserModule 的任何模块 
import { BrowserModule } from "@angular/platform-browser"
// NgModule: Angular 模块装饰器
import { NgModule } from "@angular/core"
// 根组件
import { AppComponent } from "./app.component"
import { SharedModule } from "./shared/shared.module";
import { ContentProjectionComponent } from './content-projection/content-projection.component';
import { HoverDirective } from './directives/hover.directive';
import { StringchunckPipe } from './pipes/stringchunck.pipe';
import { PersonComponent } from './components/person/person.component';
import { ChildComponent } from './components/child/child.component';
import { DemoModule } from "./demo/demo.module";
import { FormComponent } from './components/form/form.component';
import { FormsModule } from "@angular/forms"
import { ReactiveFormsModule } from "@angular/forms";
import { FormArrayComponent } from './components/form-array/form-array.component';
import { FormBuilderComponent } from './components/form-builder/form-builder.component';
import { FormCheckboxComponent } from './components/form-checkbox/form-checkbox.component';
import { FormMethodComponent } from './components/form-method/form-method.component';
import { RouterModule, Routes } from "@angular/router";
import { HomeComponent } from './pages/home/home.component';
import { AboutComponent } from './pages/about/about.component';
import { NavigationComponent } from './pages/navigation/navigation.component';
import { LayoutComponent } from './pages/layout/layout.component';

//  路由规则
const routes: Routes = [
  {
    path: "home",
    component: HomeComponent
  },
  {
    path: "about",
    component: AboutComponent
  },
  {
    path: "",
    // 重定向
    redirectTo: "home",
    // 完全匹配
    pathMatch: "full"
  },
  { path: "**", component: Not"}  
]

// 调用 NgModule 装饰器, 告诉 Angular 当前类表示的是 Angular 模块
@NgModule({
  // 声明当前模块拥有哪些组件
  declarations: [AppComponent,
    ContentProjectionComponent,
    HoverDirective,
    StringchunckPipe,
    PersonComponent,
    ChildComponent,
    FormComponent,
    FormArrayComponent,
    FormBuilderComponent,
    FormCheckboxComponent,
    FormMethodComponent, HomeComponent, AboutComponent, NavigationComponent, LayoutComponent],
  // 声明当前模块依赖了哪些其他模块
  imports: [BrowserModule,
    SharedModule,
    DemoModule,
    FormsModule,
    ReactiveFormsModule,
    RouterModule.forRoot(routes, { useHash: true })],
  // 声明服务的作用域, 数组中接收服务类, 表示该服务只能在当前模块的组件中使用
  providers: [],
  // 可引导组件, Angular 会在引导过程中把它加载到 DOM 中
  bootstrap: [AppComponent]
})
export class AppModule { }