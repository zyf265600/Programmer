import { AfterViewInit, Directive, ElementRef } from '@angular/core';

@Directive({
  selector: '[appHover]'
})
export class HoverDirective implements AfterViewInit{

  constructor(private elementRef: ElementRef) {
    console.log(this.elementRef);
  }

  

}
