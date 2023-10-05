import { AfterViewInit, Directive, ElementRef, Input } from '@angular/core';

@Directive({
  selector: '[appHover]'
})
export class HoverDirective implements AfterViewInit{
  @Input("appHover") app
  element: HTMLElement;

  constructor(private elementRef: ElementRef) {
    this.element = elementRef.nativeElement;
  }

  ngAfterViewInit(): void {
    this.element.style.backgroundColor = 'red';
  }

}
