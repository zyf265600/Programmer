import { getTopsecretResolver } from '../guards/get-topsecret.resolver';
import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { LoginComponent } from './pages/login/login.component';
import { RegisterComponent } from './pages/register/register.component';
import { SecretComponent } from './pages/secret/secret.component';
import { AuthGuard } from '../guards/auth.guard';
import { TopsecretComponent } from './pages/topsecret/topsecret.component';
import { TopsecretGuard } from '../guards/topsecret.guard';
import { UnsaveGuard } from '../guards/unsave.guard';
import { GetTopsecret } from '../guards/get-topsecret.resolver';


const routes: Routes = [
  {
    path: "login",
    component: LoginComponent
  },
  {
    path: "register",
    component: RegisterComponent
  },
  {
    path: "secret",
    component: SecretComponent,
    canActivate: [AuthGuard], //可以放多个路由守卫，只有全部通过才能进入
    canActivateChild: [TopsecretGuard],
    canDeactivate: [UnsaveGuard],
  
    children: [
      {
        path: "topsecret",
        resolve: {
          name: GetTopsecret
        },
        component: TopsecretComponent
      }

    ]
  }

];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule]
})
export class UserRoutingModule { }
