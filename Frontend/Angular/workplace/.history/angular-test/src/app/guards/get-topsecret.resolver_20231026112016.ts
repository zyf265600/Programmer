import { Injectable } from '@angular/core';
import { Router, Resolve} from '@angular/router';
import { Observable, of } from 'rxjs';

@Injectable({
  providedIn: "root"
})
export const getTopsecretResolver: ResolveFn<boolean> = (route, state) => {
  return true;
};
