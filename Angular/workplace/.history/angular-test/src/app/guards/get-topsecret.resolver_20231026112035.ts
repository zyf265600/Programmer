import { Injectable } from '@angular/core';
import { Router, Resolve} from '@angular/router';
import { Observable, of } from 'rxjs';

@Injectable({
  providedIn: "root"
})
export class GetTopsec implements Resolve<returnType> {
  resolve(): returnType {
    return new Promise(function (resolve) {
      setTimeout(() => {
        resolve({ name: "张三" })
      }, 2000)
    })
  }
}
