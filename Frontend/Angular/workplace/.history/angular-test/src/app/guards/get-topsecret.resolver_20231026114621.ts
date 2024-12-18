import { Injectable } from '@angular/core';
import { Router, Resolve, ActivatedRouteSnapshot, RouterStateSnapshot} from '@angular/router';
import { Observable, of } from 'rxjs';

@Injectable({
  providedIn: "root"
})
export class GetTopsecret implements Resolve<string> {
  resolve(route: ActivatedRouteSnapshot, state: RouterStateSnapshot): Promise<string> {
    return new Promise((resolve) => {
      setTimeout(() => {
        resolve("这是一条Topsecret信息");
      }
    }
  }
}
