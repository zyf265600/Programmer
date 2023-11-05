import { Injectable } from '@angular/core';
import { Router, Resolve, ActivatedRouteSnapshot, RouterStateSnapshot} from '@angular/router';
import { Observable, of } from 'rxjs';

@Injectable({
  providedIn: "root"
})
export class GetTopsecret implements Resolve<boolean> {
  resolve(route: ActivatedRouteSnapshot, state: RouterStateSnapshot): Observable<boolean> {
    return 
  }
}
