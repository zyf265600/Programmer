import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AuthcheckService {
  private permission: boolean = false;

  constructor() {
    let permission: boolean = false;
  }

  canCheck(input: string): boolean {
    if (input === '12345') {
      return true;
    } else {
      return false;
    }

  }

  setPermission(input: string): void { }

  getPermission(): boolean {
    return this.permission;
  }

}
