import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AuthcheckService {
  private permission: boolean;

  constructor() {
    this.permission = false;
  }

  canCheck(input: string): boolean {
    if (input === '12345') {
      return true;
    } else {
      return false;
    }

  }

  setPermission(input: string): void {
    this.permission = this.canCheck(input);
   }

  getPermission(): boolean {
    return this.permission;
  }

}
