import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AuthcheckService {
  
  constructor() {
  private permission: boolean = false;
}

canCheck(input: string): boolean {
  if (input === '12345') {
    return true;
  } else {
    return false;
  }

}

setPermission(input: string): void {}

getPermission(): boolean {

}

}
