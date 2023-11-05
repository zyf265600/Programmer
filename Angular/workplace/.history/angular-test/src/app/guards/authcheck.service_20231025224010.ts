import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AuthcheckService {

  canCheck(input: string): boolean {
    if (input === 'admin') {
      return true;
    }
    return false;
  }

}
