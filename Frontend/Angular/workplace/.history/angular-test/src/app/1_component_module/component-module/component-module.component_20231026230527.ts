import { Component } from '@angular/core';

@Component({
  selector: 'app-component-module',
  templateUrl: './component-module.component.html',
  styleUrls: ['./component-module.component.css']
})
export class ComponentModuleComponent {
  title: string = 'angular-test';
  message: string = 'Bonding Data';
}
