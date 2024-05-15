import { Injectable } from '@angular/core';
import { Router, Resolve, ActivatedRouteSnapshot, RouterStateSnapshot } from '@angular/router';
import { Observable, of } from 'rxjs';

@Injectable({
  providedIn: "root"
})
export class GetTopsecret implements Resolve<string> {
  resolve(route: ActivatedRouteSnapshot, state: RouterStateSnapshot): Promise<string> {
    return new Promise((resolve) => {
      setTimeout(() => {
        resolve("This is a Top Secret!");
      }, 2000)
    }
  }
}
