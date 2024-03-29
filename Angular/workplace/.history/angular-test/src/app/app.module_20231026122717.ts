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
import { HomeComponent } from './12_Router/pages/home/home.component';
import { AboutComponent } from './12_Router/pages/about/about.component';
import { NavigationComponent } from './12_Router/pages/navigation/navigation.component';
import { LayoutComponent } from './12_Router/pages/layout/layout.component';
import { NotFoundComponent } from './12_Router/pages/not-found/not-found.component';
import { HttpClientModule } from "@angular/common/http";
import { HttpComponent } from './http/http.component';
import { RouterComponent } from './12_Router/router/router.component';
import { NavigatorComponent } from './navigator/navigator.component';
import { AppRoutingModule } from "./app-routing.module";
import { ComponentComponent } from './1_Component_Module/component_module/component.component';
import { ModuleComponent } from './1_Component_Module/module/module.component';
import { ComponentModuleComponent } from './1_component_module/component-module/component-module.component';

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
    FormMethodComponent,
    HomeComponent, AboutComponent, NavigationComponent, LayoutComponent,
    NotFoundComponent, HttpComponent, RouterComponent, NavigatorComponent, ComponentModuleComponent],
  // 声明当前模块依赖了哪些其他模块
  imports: [BrowserModule,
    SharedModule,
    DemoModule,
    FormsModule,
    ReactiveFormsModule,
    AppRoutingModule,
    HttpClientModule],
  // 声明服务的作用域, 数组中接收服务类, 表示该服务只能在当前模块的组件中使用
  providers: [],
  // 可引导组件, Angular 会在引导过程中把它加载到 DOM 中
  bootstrap: [AppComponent]
})
export class AppModule { }