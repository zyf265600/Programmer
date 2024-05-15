import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AuthcheckService {

  canCheck(input: string): boolean {
    if (input === '12345') {
      return true;
    }
    return false;
  }

}
