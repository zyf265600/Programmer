import { Injectable } from '@angular/core';
import { CanActivate, ActivatedRouteSnapshot, RouterStateSnapshot, UrlTree, Router } from '@angular/router';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class AuthGuard implements CanActivate {
  constructor(private router: Router) { 

  }

  canActivate(
    route: ActivatedRouteSnapshot, // 待激活路由快照
    state: RouterStateSnapshot // 路由状态快照
  ): Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree {

    // alert("请先登录");

    // 用于实现跳转
    // return this.router.createUrlTree(["/navigator"]);
    // 禁止访问目标路由
    // return false;
    // 允许访问目标路由
    return true
  }
}