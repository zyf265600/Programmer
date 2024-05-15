import { Injectable } from "@angular/core"
import { CanActivateChild, ActivatedRouteSnapshot, RouterStateSnapshot, UrlTree } from "@angular/router"
import { Observable } from "rxjs"
import { AuthcheckService } from "./authcheck.service";

@Injectable({
  providedIn: "root"
})
export class TopsecretGuard implements CanActivateChild {
  constructor(private authCheck: AuthcheckService) {}

  canActivateChild(
    childRoute: ActivatedRouteSnapshot, // 待激活路由快照
    state: RouterStateSnapshot // 路由状态快照
  ): Observable<boolean | UrlTree>
    | Promise<boolean | UrlTree>
    | boolean
    | UrlTree {

    const isLoggedIn = this.authCheck.getPermission();
    if (isLoggedIn) {
      return true;
    }
    else {
      alert("请输入密码，并确保密码正确");
      return false;
    }

    // 用于实现跳转
    // return this.router.createUrlTree(["/navigator"]);
    // 禁止访问目标路由
    // return false;
    // 允许访问目标路由
    // return true
  }
}
