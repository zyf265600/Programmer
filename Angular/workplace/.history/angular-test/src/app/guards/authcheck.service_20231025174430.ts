import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AuthcheckService {

  canCheck(): boolean {
    return false;
  }

}
