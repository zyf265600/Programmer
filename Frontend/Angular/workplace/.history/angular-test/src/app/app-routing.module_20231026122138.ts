import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { RouterModule, Routes } from '@angular/router';
import { NavigatorComponent } from './navigator/navigator.component';
import { AboutComponent } from './12_Router/pages/about/about.component';
import { HomeComponent } from './12_Router/pages/home/home.component';
import { NotFoundComponent } from './12_Router/pages/not-found/not-found.component';
import { RouterComponent } from './12_Router/router/router.component';

//  路由规则
const routes: Routes = [
  {
    path: "navigator",
    component: NavigatorComponent,
  }
  ,
  {
    path: "user",
    loadChildren: () => import("./user/user.module").then(m => {
      console.log(m);
      return m.UserModule
    })
  }
  ,
  {}
  ,
  {
    path: "router",
    component: RouterComponent,

    children: [
      {
        path: "home",
        component: HomeComponent,
        outlet: "router_first",
      },
      {
        path: "about",
        component: AboutComponent,
        outlet: "router_first"
      },
      {
        path: "",
        // 重定向
        redirectTo: "home",
        // 完全匹配
        pathMatch: "full",
        outlet: "router_first"
      }
    ]
  }
  ,
  {
    path: "",
    redirectTo: "/navigator",
    pathMatch: "full"
  }
  ,
  {
    path: "**",
    component: NotFoundComponent
  }
]

@NgModule({
  declarations: [],
  imports: [
    CommonModule,
    RouterModule.forRoot(routes)
  ],
  exports: [RouterModule]
})
export class AppRoutingModule { }
